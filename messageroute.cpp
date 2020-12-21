#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 7;
const int MOD = 1e9 + 7;

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
    setIO();
    int n, m; cin >> n >> m;
    vi adj[n+1];
    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    queue<int> bfs;
    bool visited[n+1] = {false};
    bfs.push(1);
    int depth[n+1] = {1, 1};
    int path[n+1];
    while(!bfs.empty()) {
        trav(next, adj[bfs.front()]) {
            if(visited[next]) continue;
            depth[next] = depth[bfs.front()] + 1;
            visited[next] = true;
            path[next] = bfs.front();
            bfs.push(next);
        }
        bfs.pop();
    }
    if(depth[n] == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << depth[n] << "\n";
    vi ans;
    int curr = n;
    do {
        ans.pb(curr);
        curr = path[curr];
    } while(curr != 1);
    cout << "1 ";
    for(int i = ans.size()-1; i > 0; --i) {
        cout << ans[i] << " ";
    }
    cout << ans[0] << "\n";
}

/*
One bug was not initializing the visited array to false.
Need to remember to do that since I'm not declaring globally
*/