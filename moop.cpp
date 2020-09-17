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
    setIO("moop");
    int N; cin >> N;
    pii p[N]; // coordinates of the moo particles
    for(auto& a : p) cin >> a.f >> a.s;
    sort(p, p+N); //hopefully it breaks ties correctly? idk
    int ans = 1; //# of connected components encountered so far
    int miny = p[0].s;
    int suff[N]; //suffix maximums
    suff[N-1] = p[N-1].s;
    for(int i = N-2; i >= 0; --i)
        suff[i] = max(suff[i+1], p[i].s);
    for(int i = 1; i < N; ++i) {
        if(suff[i] < miny) {
            ans++; miny = p[i].s;
        }
        else {
            miny = min(miny, p[i].s);
        }
    }
    cout << ans << "\n";
}

/*
I quickly figured out that this was just the number of connected components,
but I did not know how to compute that. Finding all the edges would obviously
TLE. I thought of sorting by x-coordinates. Should have just gone the extra
step to figure out how maximum/minimum y-coordinates make the components,
because that was all I was missing (of course, that is a pretty big chunk
of the problem).

Nice problem! Implementation was easy.
*/
