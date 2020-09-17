#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

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
    setIO();
    int n; ll x; cin >> n >> x;
    pii a[n];
    for(int i = 0; i < n; i++) {
    	cin >> a[i].f;
    	a[i].s = i;
    }
    sort(a, a+n);
    int p1 = 0; int p2 = n-1;
    while(p1 < p2) {
    	ll sum = a[p1].f + a[p2].f;
    	if(sum == x) {
    		cout << a[p1].s+1 << " " << a[p2].s+1 << "\n";
    		return 0;
    	}
    	if(sum < x) p1++;
    	else p2--;
    }
    cout << "IMPOSSIBLE\n";
}