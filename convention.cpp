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

/*
Simply binary search the answer
*/

int main() {
    setIO("convention");
    int N, M, C; cin >> N >> M >> C;
    int a[N];//arrival time of each cow
    for(int& c : a) cin >> c;
    sort(a, a+N);

    //the binary search
    int lo = 0, hi = 1e9;
    while(lo < hi-1) {
        int mid = (lo+hi)/2;

        //info about the current bus we are loading
        int bus = 1; int firstCow = a[0]; int cowsOnBus = 1;
        for(int i = 1; i < N; ++i) {
            if(cowsOnBus < C && a[i] - firstCow <= mid) {
                cowsOnBus++;
            }
            else {
                cowsOnBus = 1; ++bus; firstCow = a[i];
            }
        }
        if(bus > M) lo = mid;
        else hi = mid;
    }
    cout << hi << "\n";
}

/*
The problem seems impossible at first but once you realize to binary search the
answer, it becomes almost trivial.

Implementation was really smooth.
*/