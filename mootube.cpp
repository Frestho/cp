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

vector<pii> adj[5010];
bool visited[5010];
int K;
int cnt;
void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true; ++cnt;
    // process node s
    for (auto u: adj[s])  if(u.s >= K) dfs(u.f);
}

int main() {
    setIO("mootube");
    int N, Q; cin >> N >> Q;
    for(int i = 0; i < N-1; ++i) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    for(int i = 0; i < Q; ++i) {
        int k, v; cin >> k >> v;
        K = k; cnt = 0; memset(visited, false, sizeof(visited));
        dfs(v);
        cout << cnt - 1 << "\n";
    }
}

/*
Finished, again, very easy. My code worked first try. I'm not sure if using
pairs was the most clean way to handle weighted edges though. Gonna look more
into that.
*/