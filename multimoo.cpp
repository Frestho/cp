#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 257;

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
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int N;

void dfs(int x, int y, int label) {
    if (visited[x][y]) return;
    visited[x][y] = true;
    grid[x][y] = label;
    auto a = no[x][y];
    if(!a[0] && y > 1) dfs(x, y-1, label);
    if(!a[1] && x < N) dfs(x+1, y, label);
    if(!a[2] && y < N) dfs(x, y+1, label);
    if(!a[3] && x > 1) dfs(x-1, y, label);
}

/*
Uhh why is this marked hard? Can't you just do a simple floodfill for the first
part and try pairing everything for the second? Since N is so low

O(N^2) for the first part I think, O(N^4) for the second. 

Wait nvm N^4 is way too big
crap
*/

int main() {
    setIO();
    cin >> N;
    rep(i, 0, N) {
        rep(j, 0, N) {
            cin >> grid[i][j];
        }
    }
    bool idDone[1e6];
    vi id; // list of ID's 
}


