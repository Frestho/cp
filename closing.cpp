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

//just simulate the process lol
//didn't know this was bronze


vector<int> adj[5000];
bool visited[5000];
bool deleted[5000];
int cnt = 0;
void dfs(int s) {
    if (visited[s] || deleted[s]) return;
    visited[s] = true; ++cnt;
    // process node s
    for (auto u: adj[s]) dfs(u);
}

int main() {
    setIO("closing");
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int minUndeleted = 1;
    dfs(minUndeleted);
    if(cnt < N) cout << "NO\n"; else cout << "YES\n";
    for(int i = 0; i < N-1; ++i) {
        int a; cin >> a;
        deleted[a] = true;
        /*
        for(int node : adj[a]) {
            for(int i = 0; i < adj[node].size(); ++i) {
                if(adj[node][i] == a) {adj[node].erase(adj[node].begin() + i); break;}
            }
        }*/
        for(int i = 1; i <= N; ++i) visited[i] = false;
        while(deleted[minUndeleted]) ++minUndeleted;
        cnt = 0;
        dfs(minUndeleted);
        if(cnt == N - i - 1) cout << "YES\n"; else cout << "NO\n";
    }
}

/*
Okay, interesting exercise. I haven't done graphs in a while so I was really
rusty. The algorithm was very very simple; basic knowledge of DFS pretty much
solves it. Implementation could have gone more smoothly. The last bug I
came across was iterating from 0 to N-1 instead of 1 to N (inclusive),
since usually graph problems are not zero indexed.

I don't think my implementation was the most efficient. Just gonna do some
more graph problems and hopefully become more proficient
*/