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
    setIO("teamwork");
    int N, K; cin >> N >> K;
    int s[N];//skill levels
    trav(a, s) cin >> a;

    int ans = 0;

    //the extra slot of info goes to the max number in the final group, for O(NK)
    int dp[N][K][2];
    rep(i, 0, N) {
        rep(j, 1, K+1) {
            int& x = dp[i][j][0];
            int& y = dp[i][j][1];
            x = -1;
            if(i == 0) {
                if(j == 1) {
                    x = s[0];
                    y = s[0];
                }
                continue;
            }
            
            if(j == 1)  {
                y = s[i];
                rep(k, 1, K+1) {
                    x = max(x, dp[i-1][k][0] + y);
                }
            }
            else if(dp[i-1][j-1][0] > -1) {
                y = max(dp[i-1][j-1][1], s[i]);
                x = dp[i-1][j-1][0] - dp[i-1][j-1][1]*(j-1) + j*y;
            }
            if(i == N-1) {
                ans = max(ans, x);
            }
            //cout << i << " " << j << " " << x << " " << y << endl;
        }
    }
    cout << ans << "\n";
}
