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
    
    int n; cin >> n;
    vector<ll> start;
    vector<ll> leave;
    rep(i, 0, n) {
		ll a, b; cin >> a >> b; start.push_back(a); leave.push_back(b);
	}
	sort(all(start));sort(all(leave));
	int c = 0;
	int j = 0;
	trav(i, start) {
		if(i > leave[j]) {
			j++; //used to erase the first element but that was way to slow
		}
		else {
			c++;
		}
	}
	cout << c << "\n";
}
