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
int component[MAX_N];
string types;

void dfs(int s, int f, int label) {
    component[s] = label;
    trav(a, adj[s]) {
        if(a != f && types[s-1] == types[a-1]) dfs(a, s, label);
    }
}

int main() {
    setIO("milkvisits");
    int N, M; cin >> N >> M;
    cin >> types;
    int a, b;
    rep(i, 1, N) {
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    rep(i, 1, N+1) {
        if(component[i] == 0) {
            dfs(i, -1, i);
        }
    }

    rep(i, 0, M) {
        int a, b; char c; cin >> a >> b >> c;
        if(component[a] != component[b] || types[a-1] == c) {
            cout << 1;
            continue;
        }
        cout << 0;
    }
    cout << "\n";
}
