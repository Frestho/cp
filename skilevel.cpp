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

struct Edge {
    int a, b, w; // node a, node b, weight
};

bool cmp(const Edge& x, const Edge& y) 
{ return x.w < y.w; }

int main() {
    setIO("skilevel");
    int M, N, T; cin >> M >> N >> T;
    int grid[M][N];
    rep(i, 0, M) {
        rep(j, 0, N) {
            cin >> grid[i][j];
        }
    }

    vector<Edge> edges;
    //makes edges
    rep(i, 0, M) {
        rep(j, 0, N) {
            if(i < M-1) {
                edges.pb({i*N + j, (i+1)*N + j, abs(grid[i][j] - grid[i+1][j])});
            }
            if(j < N-1) {
                edges.pb({i*N + j, i*N + j + 1, abs(grid[i][j] - grid[i][j+1])});
            }
        }
    }
    sort(all(edges), cmp);
    vi starts;
    rep(i, 0, M) {
        rep(j, 0, N) {
            int a; cin >> a;
            if(a) starts.pb(i*N + j);
        }
    }

    DSU dsu;
    dsu.init(N*M);

    ll ans = 0;
    trav(e, edges) {
        if(dsu.sameSet(e.a, e.b)) continue;
        bool temp = true;
        if(dsu.size(e.a) >= T && dsu.size(e.b) >= T || (dsu.size(e.a) + dsu.size(e.b) < T)) temp = false;
        dsu.unite(e.a, e.b);
        if(temp) {
            rep(i, 0, starts.size()) {
                if(dsu.sameSet(e.a, starts[i])) {
                    ans += e.w;

                    //deletes element in O(1) by replacing it with the last element
                    starts[i] = starts[starts.size()-1];
                    starts.pop_back(); 
                    i--; //don't accidentally skip the element we just moved
                }
            }
        }
    }
    cout << ans << "\n";
}

/*
Damn, I think the vanila DSU I used can't be optimized enough to get full credit.
This currently gets 7/10 test cases and I can't find any other easy optimizations
besides rewriting the DSU struct, so maybe I'll redo this in the future?
*/