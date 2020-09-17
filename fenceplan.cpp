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

vi adj[100010];
bool visited[100010];
pii coords[100010];
int minx, miny, maxx, maxy = -69;
void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    if(minx == -69) minx = coords[s].f;
    else minx = min(minx, coords[s].f);
    if(miny == -69) miny = coords[s].s;
    else miny = min(miny, coords[s].s);
    if(maxx == -69) maxx = coords[s].f;
    else maxx = max(maxx, coords[s].f);
    if(maxy == -69) maxy = coords[s].s;
    else maxy = max(maxy, coords[s].s);
    // process node s
    for (auto u: adj[s]) dfs(u);
}

int main() {
    setIO("fenceplan");
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; ++i) {
        cin >> coords[i].f >> coords[i].s;
    }
    for(int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    int ans = 1e9;
    int j = 1; // points to the unvisited node with the least ID
    while(j <= N) {
        minx=-69, miny=-69, maxx=-69, maxy = -69;
        dfs(j);
        ans = min(ans, 2*(maxx - minx + maxy - miny));
        while(visited[j]) ++j;
    }
    cout << ans << "\n";
}

/*
Ez, just quite tedious
The only major bug was again, misindexing the nodes. Completely my bad
*/