#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    ll n; cin >> n;
    ll sum=0;
    ll big = INT_MIN;
    ll small = INT_MAX;
    while(n--) {
		ll a;
		cin >> a;
		small = min(small, sum);
		sum += a;
		big = max(big, sum - small);
	}
	cout << big << endl;
    return 0;
}
