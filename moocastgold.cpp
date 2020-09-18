#include <bits/stdc++.h>
using namespace std;

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

/*
binary search the answer
dfs to check it
*/

vector<int> adj[1010];
bool visited[1010];
pii coords[1001];
int mid;
int cnt = 0;
void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true; ++cnt;
    // process node s
    for (auto u: adj[s]) if((coords[s].f - coords[u].f)*(coords[s].f - coords[u].f) + 
    	(coords[s].s - coords[u].s)*(coords[s].s - coords[u].s) <= mid) dfs(u);
}

int main() {
    setIO("moocast");
    int N; cin >> N;
    for(int i = 0; i < N; ++i) {
    	cin >> coords[i].f >> coords[i].s;
    }

    for(int i = 0; i < N; ++i) {
    	for(int j = 0; j < N; ++j) {
    		adj[i].pb(j);
    	}
    }

    //binary search on the maximum distance
    //could be improved by putting the distances in a list and sorting, but whatever
    int lo = 0; int hi = 1250000000;
    while(lo < hi -1) {
    	mid = (lo + hi)/2;
    	cnt = 0;
    	memset(visited, false, sizeof(visited));
    	dfs(0);
    	if(cnt < N) lo = mid;
    	else hi = mid;
    }
    cout << hi << "\n";
}

/*
Ok solved, nice. Quite easy once you think of the binary search. Unfortunately,
at first I misread it as "find the least possible SUM of the costs", which is a
lot harder.

I'm actually surprised this fits rather comfortably under the time limit, given
that it is O(N^2 log N). Actually nvm that does make sense lol since the bound
on N is so low.

My implementation definitely isn't the fastest, but it works so who cares.
*/
