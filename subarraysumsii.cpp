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
    
    ll n, x; cin >> n >> x;
    map<ll, ll> sums;
    ll sum=0;
    ll ret = 0;
    while(n--) {
		sums[sum]++;
		ll a;
		cin >> a;
		sum += a;
		ret += sums[sum-x];
	}
	cout << ret << endl;
    return 0;
}
