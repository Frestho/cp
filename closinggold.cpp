#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 69;

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

struct DSU {
    vi e; void init(int N) { e = vi(N,-1); }
    // get representive component, uses path compression
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) { // union by size
        x = get(x), y = get(y); if (x == y) return 0;
        if (e[x] > e[y]) swap(x,y);
        e[x] += e[y]; e[y] = x; return 1;
    }
};

int main() {
    setIO("closing");
    int N, M; cin >> N >> M;
    vi adj[N]; //zero indexed!
    rep(i, 0, M) {
        int a, b; cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    int nodes[N];

    //maps a node to whether it exists yet
    map<int, bool> exists;
    trav(n, nodes) {
        cin >> n;
        n--;
    }

    DSU dsu;
    dsu.init(N);
    string ans[N];
    for(int i = N-1; i >= 0; --i) {
        exists[nodes[i]] = true;
        trav(a, adj[nodes[i]]) {
            if(exists[a])
                dsu.unite(nodes[i], a);
        }
        ans[i] = (dsu.size(nodes[i]) == N-i ? "YES\n" : "NO\n");
    }
    trav(str, ans) {
        cout << str;
    }
}

/*
Not as fast as the official solution, probably because mine uses a map. Still runs
fast enough though, so I won't touch it.

I missed the idea of processing the barns backwards (had to look at the solution).
Big dumb on my part.
*/