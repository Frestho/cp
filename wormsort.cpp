#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100010;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pii = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin); // see Input & Output
        freopen((name+".out").c_str(), "w", stdout);
    }
}

vector<pii> adj[MAX_N];
bool visited[MAX_N];
bool visited2[MAX_N]; // same as visited but ONLY IN THE CURRENT CONNECTED COMP
int c[MAX_N]; // positions of the cows
vi v; // list of visited indices in the current connected component
int mid;
void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    visited2[s] = true;
    v.pb(s);
    // process node s
    for (auto u: adj[s]) if(u.s >= mid) dfs(u.f);
}

int main() {
    setIO("wormsort");
    int N, M; cin >> N >> M;
    
    for(int i = 1; i <= N; ++i) cin >> c[i];
    for(int i = 0; i < M; ++i) {
    	int a, b, c; cin >> a >> b >> c;
    	adj[a].pb(mp(b, c)); adj[b].pb(mp(a, c));
    }
    // test if already sorted
    for(int i = 1; i <= N; ++i) {
    	if(c[i] != i) break;
    	if(i == N) {
    		cout << -1 << "\n";
    		return 0;
    	}
    }

    //do a binary search
    int lo = 1, hi = 1e9;
    while(lo < hi-1) {
    	mid = (lo + hi)/2;
    	bool works = true;
        int tmp = 1; // least position that is not visited
    	memset(visited, false, sizeof(visited));
    	while(tmp <= N) {
    		memset(visited2, false, sizeof(visited2));
    		dfs(tmp);
    		//check if the visited elements are in a permuation
    		for(int node : v) {
    			if(!visited2[c[node]]) {works = false; break;}
    		}
    		v.clear();
    		while(visited[tmp]) ++tmp; //should automatically break when tmp>=N
    	}
    	if(works) lo = mid;
    	else hi = mid;
    }
    cout << lo << "\n";
}

/*
Finally finished! Cool problem I'd say. In January when I took this contest
I thought of binary searching the answer but didn't have enough graph
knowledge to implement that. I encountered a few bugs, including misindexing
(yet again...), printing mid instead of low (doesn't work because sometimes)
the outer while loop exits and doesn't get a chance to update mid.
*/