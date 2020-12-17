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
    setIO("helpcross");
    int C, N; cin >> C >> N;
    vector<pii> events;
    rep(i, 0, C) {
        int a; cin >> a;
        events.pb(mp(a, INT_MAX));
    }
    rep(i, 0, N) {
        int a, b; cin >> a >> b;
        events.pb(mp(a, b));
    }
    sort(all(events));
    multiset<int> ends;
    int ans = 0;
    trav(p, events) {
        if(p.s <= 1e9) {
            ends.insert(p.s);
            continue;
        }
        while(ends.size() && *ends.begin() < p.f) {
            ends.erase(ends.begin());
        }
        if(ends.size()) {
            ans++;
            ends.erase(ends.begin());
        }
    }
    cout << ans << "\n";
}
