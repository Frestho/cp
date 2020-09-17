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

//bin search the answer, use some greedy (always place cows as far left as possible)
//probably O((N+M)log10^18)? 

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    // process node s
    for (auto u: adj[s]) {
        dfs(u);
    }
}


int main() {
    setIO("socdist");
    int N, M; cin >> N >> M;
    pair<ll, ll> g[M]; //grass intervals
    for(auto& p : g) cin >> p.f >> p.s;
    sort(g, g+M);
    //binary search
    ll lo = 0, hi = 1e18;
    while(lo < hi-1) {
        ll mid = (lo+hi)/2;
        ll prevCow = g[0].f; // position of the previous cow that was placed
        int currI = 0; // current interval
        for(int i = 1; i < N; ++i) { //iterating through the cows
            while(currI < M && g[currI].s < prevCow + mid) currI++;
            if(currI == M)
                i = N;
            prevCow = max(g[currI].f, prevCow + mid);
        }
        if(currI == M) hi = mid;
        else lo = mid;
    }
    cout << lo << "\n";
}

/*
Finished! Pretty easy conceptually. Implementation ran into a few hiccups but
nothing major, so it only took half an hour. Running tests in onlinegdb
definitely helped. Not much to say honestly
*/