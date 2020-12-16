#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)

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

vi adj[MAX_N];
bool visited[MAX_N];
map<int, int> team; //maps player i to team t_i
bool bad = false;

void dfs(int s, int t) {
    if (visited[s]) return;
    visited[s] = true;
    team[s] = t;
    for (auto u: adj[s]) {
        if(team[u] == t) {
            bad = true;
            return;
        }
        dfs(u, (t%2)+1);
    }
}

int main() {
    setIO();
    int n, m; cin >> n >> m;
    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 1; i <= n; ++i) {
        if(visited[i]) continue;
        dfs(i, 1);
        if(bad) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    rep(i, 1, n)
        cout << team[i] << " ";
    cout << team[n] << "\n";
}
