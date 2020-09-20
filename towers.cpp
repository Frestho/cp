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

//I think you just always place the block on the smallest platform available
//(where making another tower is an infinite platform)

int main() {
    setIO();
    multiset<int> t; // top of each tower
    //t.insert(MAX_N);
    int n; cin >> n;
    rep(i, 0, n) {
        int a; cin >> a;
        auto it = t.upper_bound(a);
        if(it == t.end()) {
            t.insert(a);
        }
        else {
            t.erase(it);
            t.insert(a);
        }
    }
    cout << sz(t) << "\n";
}

/*
Ez greedy algorithm. Could be made faster by using vectors instead of sets.
*/
