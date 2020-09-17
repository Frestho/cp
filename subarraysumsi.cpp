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
    int a[n];
    for(auto& ai : a) cin >> ai;
    int p1 = -1, p2 = 0;
    ll sum = a[0];
    int count = 0;
    while(true) {
        //cout << p1 << " " << p2 << " " << sum;
        if(sum == x) {
            //cout << " bingo";
            ++count;
            ++p2; ++p1;
            if(p2 >= n) {
                break;
            }
            sum += a[p2];
            sum -= a[p1];
        }else if(sum < x) {
            p2++;
            if(p2 == n) break;
            sum += a[p2];
        } else {
            p1++;
            sum -= a[p1];
        }
        //cout << endl;
    }
    cout << count << "\n";
}