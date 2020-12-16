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

vector<pair<int, char>> adj[MAX_N]; // for each node, stores a pair denoting adjacent node and S/D
bool visited[MAX_N];
map<int, int> pasture; //maps player i to pasture t_i
bool bad = false;

void dfs(int s, int t) {
    if (visited[s]) return;
    visited[s] = true;
    pasture[s] = t;
    for (auto u: adj[s]) {
        if(u.s == 'D') {
            if(pasture[u.f] == t) {
                bad = true;
                return;
            }
            dfs(u.f, (t%2)+1);
        } else {
            if(pasture[u.f] == (t%2)+1) {
                bad = true;
                return;
            }
            dfs(u.f, t);
        }
    }
}

int main() {
    setIO("revegetate");
    int n, m; cin >> n >> m;
    rep(i, 0, m) {
        char c; cin >> c;
        int a, b; cin >> a >> b;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    int zeroes = 0;
    for(int i = 1; i <= n; ++i) {
        if(visited[i]) continue;
        zeroes++;
        dfs(i, 1);
        if(bad) {
            cout << "0\n";
            return 0;
        }
    }
    cout << 1;
    rep(i, 0, zeroes)
        cout << 0;
    cout << "\n";
}

/*
basically DFS and the restrictions force any node recursively encountered to
be a certain way. any time you encounter a new node, you have a choice between
one seed or the other, so multiply by two.

very similar to buildingteams.
*/