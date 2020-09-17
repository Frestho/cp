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
    int n, x; cin >> n >> x;
    pii a[n];
    for(int i = 0; i < n; ++i){
        int c; cin >> c;
        a[i] = mp(c, i);
    } 
    sort(a, a+n);
    for(int p3 = 0; p3 < n-2; ++p3) {
        if(a[p3].f + a[n-1].f + a[n-2].f < x) continue;
        if(a[p3].f + a[p3+1].f + a[p3+2].f > x) break;
        int p1 = p3+1, p2 = n-1;
        int sum = a[p1].f + a[p2].f;
        while(p1 < p2) {
            if(sum == x-a[p3].f) {
                cout << a[p1].s + 1 << " " << a[p2].s + 1 << " " << a[p3].s + 1 << "\n";
                return 0;
            }
            if(sum < x-a[p3].f) {
                p1++;
            } else {
                p2--;
            }
            sum = a[p1].f + a[p2].f;
        }
    }
    cout << "IMPOSSIBLE\n";
    /* this also happens to be O n^2 log n rip
    vector<pair<int, pii>> twoSum;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            twoSum.pb(mp(a[i] + a[j], mp(i, j)));
        }
    }
    int p = n-1;
    int sum;
    sort(all(twoSum));
    for(auto t : twoSum) {
        sum = t.f + a[p];
        while (sum > x) {
            sum -= a[p--];
        }
        if(p < 0) break;
        if(sum == x && p+1 != t.s.f +1 && t.s.f +1 != t.s.s +1 && t.s.s +1 != p+1) {
            cout << p+1 << " " << t.s.f +1 << " " << t.s.s +1<< "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << "\n";

    /* oops this is n^2 logn
    set<pair<int, pii>> twoSum;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            twoSum.insert(mp(a[i] + a[j], mp(i, j)));
        }
    }
    int p = n-1;
    int sum;
    for(auto t : twoSum) {
        sum = t.f + a[p];
        while (sum > x) {
            sum -= a[p--];
        }
        if(sum == x && p+1 != t.s.f +1 && t.s.f +1 != t.s.s +1 && t.s.s +1 != p+1) {
            cout << p+1 << " " << t.s.f +1 << " " << t.s.s +1<< "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << "\n";*/
}
