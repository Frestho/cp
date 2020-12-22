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
    setIO("snakes");
    int N, K; cin >> N >> K;
    int total = 0;
    int s[N];
    trav(a, s) { cin >> a; total += a; }

    //prefix maximums; pref[i][j] indicates max between i and j
    int pref[N][N];
    rep(i, 0, N) {
        int temp = s[i];
        rep(j, i, N) {
            temp = max(temp, s[j]);
            pref[i][j] = temp;
            //cout << i << " " << j << " " << pref[i][j] << "\n";
        }
    }

    int ans = INT_MAX;

    //dp[i][j] indicates least sum over first i groups with exactly j changes
    int dp[N][K+1];
    rep(i, 0, N) {
        rep(j, 0, K+1) {
            int& x = dp[i][j];
            x = INT_MAX;
            if(j == 0) {
                x = (i+1)*pref[0][i];
                continue;
            }
            for(int k = j-1; k < i; k++) {
                x = min(x, dp[k][j-1] + pref[k+1][i]*(i - k));
            }
            if(i == N-1) {
                ans = min(ans, x - total);
            }
            //cout << i << " " << j << " " << x << "\n";
        }
    }
    cout << ans << "\n";
}

/*
Had to do a lot of trial and error oops
^ Should probably plan more before doing
Print statements are great for debugging

Wait lol my solution is even faster than the official one
Thanks to my prefix maximums
Nice
*/