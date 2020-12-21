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

int main() {
    setIO("time");
    int N, M, C; cin >> N >> M >> C;
    int m[N+1];
    rep(i, 1, N+1) {
        cin >> m[i];
    }

    // dp[i][j] is max amount of money after i days, on city j
    // INT_MIN for impossible
    int dp[500][N+1]; 
    rep(i, 0, 500) {
        rep(j, 0, N+1) {
            dp[i][j] = -1;
        }
    }

    vi adj[N+1]; //important: this is BACKWARDS! adj[i] is the list of nodes that go TO i
    rep(i, 0, M) {
        int a, b; cin >> a >> b;
        adj[b].pb(a);
    }
    int ans = 0;
    rep(i, 0, 500) {
        rep(j, 1, N+1) {
            int& x = dp[i][j];
            if(i == 0 && j == 1) {
                x = 0;
                continue;
            }
            x = -1;
            if(i == 0) continue;
            trav(node, adj[j]) {
                if(dp[i-1][node] > -1)
                    x = max(x, dp[i-1][node]);
            }
            if(x > -1)
                x += m[j];
            if(j == 1) ans = max(ans, x - C*i*i);
            //cout << i << " " << j << " " << x << endl;
        }
    }
    cout << ans << "\n";
}
