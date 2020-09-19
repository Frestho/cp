#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e3 + 7;

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

//vi adj[MAX_N][MAX_N];
string grid[MAX_N];
//zero indexed!
bool visited[MAX_N][MAX_N];

//actually wait lol do we even need to make an adj list


int area = 0;
int peri = 0;
void dfs(int x, int y) {
    if (visited[x][y]) return;
    visited[x][y] = true;
    ++area;
    //decrease as necessary later
    peri += 4;
    //should completely replace the adj list?
    if(x > 0 && grid[x-1][y] == '#') dfs(x-1, y), --peri;
    if(grid[x+1][y] == '#') dfs(x+1, y), --peri;
    if(y > 0 && grid[x][y-1] == '#') dfs(x, y-1), --peri;
    if(grid[x][y+1] == '#') dfs(x, y+1), --peri;
}

int maxArea = 0;
int minPeri = INT_MAX;

int main() {
    setIO("perimeter");
    int N; cin >> N;

    
    rep(i, 0, N) {
        cin >> grid[i];
    }
    rep(i, 0, N) {
        rep(j, 0, N) {
            area = 0; peri = 0;
            if(!visited[i][j] && grid[i][j] == '#') dfs(i, j);
            if(area > maxArea) {
                maxArea = area;
                minPeri = peri;
            } else if (area == maxArea && peri < minPeri)
                minPeri = peri;
        }
    }
    cout << maxArea << " " << minPeri << "\n";
}

/*
Quite easy, had two bugs. First, I tried to get away with ignoring array
bounds. Second, I printed out area and peri instead of maxArea, etc. That was
stupid lol.
*/
