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

bool sortinrev(const pair<int,int> &a, const pair<int,int> &b) { 
       return (a.first > b.first); 
} 

int main() {
    setIO("split");
    int N; cin >> N;
    vector<pii> xsorted;
    vector<pii> ysorted;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        xsorted.pb(mp(a, b)); ysorted.pb(mp(b, a));
    }
    sort(all(xsorted));
    sort(all(ysorted));
    ll leftminy[N];
    ll leftmaxy[N];
    ll rightminy[N];
    ll rightmaxy[N];
    leftminy[0] = leftmaxy[0] = xsorted[0].s;
    rightminy[N-1] = rightmaxy[N-1] = xsorted[N-1].s;
    for(int i = 1; i < N; i++) {
        leftminy[i] = min(leftminy[i-1], xsorted[i].s);
        leftmaxy[i] = max(leftmaxy[i-1], xsorted[i].s);
        rightmaxy[N-i-1] = max(rightmaxy[N-i], xsorted[N-i-1].s);
        rightminy[N-i-1] = min(rightminy[N-i], xsorted[N-i-1].s);
    }
    /* ok fuck this problem it's literally trivial i found the main idea
    in 1 minute but the implementation is cancer */
}
