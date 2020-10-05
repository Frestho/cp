#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 257;

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
    int t; cin >> t;
    rep(arst, 0, t) {
        int n, m; cin >> n >> m;
        ll grid[n][m];
        rep(i, 0, n)
            rep(j, 0, m)
                cin >> grid[i][j];
        ll ans = 0;
        rep(i, 0, (n+1)/2) {
            rep(j, 0, (m+1)/2) {
                vector<ll> temp;
                if(i == n-i-1) {
                    temp.pb(grid[i][j]);
                    temp.pb(grid[i][m-j-1]);
                    ans += max(temp[0]-temp[1], temp[1]-temp[0]);
                }
                else if(j == m-j-1) {
                    temp.pb(grid[i][j]);
                    temp.pb(grid[n-i-1][j]);
                    ans += max(temp[0]-temp[1], temp[1]-temp[0]);
                }
                else {
                    temp.pb(grid[i][j]);
                    temp.pb(grid[n-i-1][j]);
                    temp.pb(grid[i][m-j-1]);
                    temp.pb(grid[n-i-1][m-j-1]);
                    sort(all(temp));
                    ans += temp[1]-temp[0];
                    ans += temp[2]-temp[1];
                    ans += temp[3]-temp[1];
                }
            }
        }
        cout << ans << "\n";
    }
}
