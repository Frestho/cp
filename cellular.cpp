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
    int n, m; cin >> n >> m;
    int a[n];
    int b[m];
    for(int& c : a) cin >> c;
    for(int& c : b) cin >> c;
    int j = 0;
    int ans = 0;
    for(int c : a) {
        while(b[j] < c && j < m) ++j;
        if(j == 0) 
            ans = max(ans, b[j]-c);
        else if(j < m)
            ans = max(ans, min(b[j]-c, c-b[j-1]));
        else
            ans = max(ans, c-b[j-1]);
    }
    cout << ans << "\n";
}
