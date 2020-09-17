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
    int n, t; cin >> n >> t;
    int a[n];
    for(int& c : a) cin >> c;
    int p = -1, q = 0;
    int sum = a[0];
    int ans = 0;
    while(q < n) {
        while(sum > t) {
            sum -= a[++p];
        }
        ans = max(ans, q-p);
        sum += a[++q];
    }
    cout << ans << "\n";
}

