#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e9+7;

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

//completely trivial, just do the shortest tasks first

int main() {
    setIO();
    int n; cin >> n;
    pair<ll, ll> t[n];
    trav(c, t) cin >> c.f >> c.s;
    sort(t, t+n);
    ll tme = 0;
    ll ans = 0;
    trav(task, t) {
        tme += task.f;
        ans += task.s - tme;
    }
    cout << ans << "\n";
}

/*
Ez greedy algorithm. Only bug was not using ll's, easily fixed.
*/
