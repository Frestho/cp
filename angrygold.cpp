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
    setIO("angry");
    int N; cin >> N;
    set<int> bales;
    rep(i, 0, N) {
        int temp; cin >> temp; bales.insert(2*temp);
    }
    int bFirst = *bales.begin();
    int bLast = *prev(bales.end());
    int lo = 1; int hi = min(bLast - bFirst)/2; 
    while(lo < hi) {
        int mid = (lo+hi)/2;
        int l = bFirst + mid; int h = bLast - mid + 1;
        while(l < h-1) {
            int loc = (l+h)/2;
            int radius = mid;
            //current leftMost bale (before explosion happens there)
            int leftMost1 = loc;
            //updated leftMost bale
            int leftMost2;

            while(true) {
                leftMost2 = *bales.lower_bound(leftMost1 - radius);
                if(leftMost2 == bFirst) { //hit all the bales
                    l = loc;
                    break;
                }
                if(leftMost2 == leftMost1) { //can't reach the next bale
                    h = loc-1;
                    break;
                }
                leftMost1 = leftMost2;
                radius -= 2;
            }
        }

        //then test if it can go all the way to the right
        int radius = mid;
        //current leftMost bale (before explosion happens there)
        int rightMost1 = l;
        //updated leftMost bale
        int rightMost2;
        while(true) {
            rightMost2 = *prev(bales.upper_bound(rightMost1 + radius));
            if(rightMost2 == bLast) { //hit all the bales
                hi = mid;
                break;
            }
            if(rightMost2 == rightMost1) { //can't reach the next bale
                lo = mid+1;
                break;
            }
            rightMost1 = rightMost2;
            radius -= 2;
        }
    }
    if(hi % 2 == 1)
        cout << hi/2 << ".5\n";
    else
        cout << hi/2 << ".0\n";
}
