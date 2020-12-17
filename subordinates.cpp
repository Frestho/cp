#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 69;

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
int sub[MAX_N];

int dfs(int s) {
    if(visited[s]) return 0;
    visited[s] = true;
    int ret = 0;
    trav(a, adj[s]) {
        ret += dfs(a);
    }
    sub[s] = ret;
    return ret + 1;
}

int main() {
    setIO();
    int n; cin >> n;
    rep(i, 2, n+1) {
        int a; cin >> a;
        adj[i].pb(a);
        adj[a].pb(i);
    }
    dfs(1);
    rep(i, 1, n) {
        cout << sub[i] << " ";
    }
    cout << sub[n] << "\n";
}

/*
Very interesting application of DFS! Glad I figured this out myself.
*/