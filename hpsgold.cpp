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

int main() {
    setIO("hps");
    int N, K; cin >> N >> K;

    //dp[i][j][k]: max # of games bessie could've won after i games,
    //j switches, gesture k
    int dp[N+1][K+1][3]; 

    int moves[N+1];
    rep(i, 1, N+1) {
    	char a; cin >> a;
    	if(a == 'H') moves[i] = 0;
    	else if(a == 'P') moves[i] = 1;
    	else moves[i] = 2;
    }
    rep(i, 0, N+1) {
    	for(int j = 0; j < K + 1; ++j) {
    		rep(st, 0, 3) {
    			if(i == 0) dp[i][j][st] = 0; // no games played yet
    			else {
    				int beat = (st + 2) % 3; //st beats this
    				int beaten = (st + 1) % 3; //gets beaten by this
    				if(j == 0) dp[i][j][st] = dp[i-1][j][st] + (beat == moves[i] ? 1 : 0);
    				else dp[i][j][st] = max(max(dp[i-1][j][st],
    					dp[i-1][j-1][beat]), dp[i-1][j-1][beaten]) + (beat == moves[i] ? 1 : 0);
    			}
    		}
    	}
    }
    cout << max(max(dp[N][K][0], dp[N][K][1]), dp[N][K][2]) << "\n";
}

/*
My first non-classic DP problem. Very interesting how it is used! Still need
to wrap my head around some stuff, but I think this problem helped me understand
dp a lot better. Tracking every single possible state is very interesting.
*/