#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 69;

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

vi adj[MAX_N];
int maxDepth = 0;
int deepestNode;

void dfs(int s, int b, int depth) {
    if(depth > maxDepth) {
        maxDepth = depth;
        deepestNode = s;
    }
    trav(a, adj[s]) {
        if(a != b) dfs(a, s, depth + 1);
    }
}

int main() {
    setIO();
    int n; cin >> n;
    rep(i, 1, n) {
        int a, b; cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    dfs(1, -1, 0);
    maxDepth = 0;
    dfs(deepestNode, -1, 0);
    cout << maxDepth << "\n";
}

/*
Just implemented the second algorithm from CPH
*/