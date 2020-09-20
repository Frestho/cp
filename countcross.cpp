#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 107;

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
//NOT ZERO INDEXED
bool no[MAX_N][MAX_N][4]; //1 means no up, 2 means no right, 3 no down, 4 no left

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


int main() {
    setIO("countcross");
    int K, R; cin >> N >> K >> R;
    rep(i, 0, R) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if(c-a == 1) {
            no[a][b][1] = true; no[c][d][3] = true;
        }
        if(c-a == -1) {
            no[a][b][3] = true; no[c][d][1] = true;
        }
        if(d-b == 1) {
            no[a][b][2] = true; no[c][d][0] = true;
        }
        if(d-b == -1) {
            no[a][b][0] = true; no[c][d][2] = true;
        }
    }
    int counter = 0;
    rep(i, 1, N+1) {
        rep(j, 1, N+1) {
            if(!visited[i][j]) {
                ++counter;
                dfs(i, j, counter);
            }
        }
    }
    pii cows[K];
    rep(i, 0, K) {
        cin >> cows[i].f >> cows[i].s;
    }
    int ans = 0;
    rep(i, 0, K) {
        rep(j, i+1, K) {
            if(grid[cows[i].f][cows[i].s] != grid[cows[j].f][cows[j].s])
                ++ans;
        }
    }
    cout << ans << "\n";
}

/*
Very easy, not sure why it was marked normal instead of easy. Basic floodfill
concept of labeling the grid. 

Implementation was smooth af. Everything worked basically first try (after
some dumb stuff like not passing label into dfs() and correcting the format
of the no array), which was very nice.
*/
