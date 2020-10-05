#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 7;
const int MOD = 1e9 + 7;

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
int n, x; 
vi c;
int dp[MAX_N];

int solve(int x) {
    if(x == 0) return 0;
    if(x < 0) return MAX_N;
    if(dp[x] != -1) return dp[x];
    dp[x] = MAX_N;
    trav(a, c) dp[x] = min(solve(x-a)+1, dp[x]);
    return dp[x];
}

int main() {
memset(dp, -1, sizeof(dp));
    setIO();
    cin >> n >> x;
    int a;
    rep(i, 0, n) cin >> a, c.pb(a);
    if(solve(x) < MAX_N)
    cout << solve(x) << "\n";
    else cout << -1 << "\n";
}

/*
good beginner dp exercise
*/
