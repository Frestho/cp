#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 21;

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
int a, b, c, d;

int totalA = 0; // total connected components of A;
int totalB = 0; // same for B;

void dfs(int x, int y) {
    if (visited[x][y]) return;
    visited[x][y] = true;
    //only inside the rectangle with corners (a, b) and (c, d)
    if(x > a && grid[x-1][y] == grid[x][y]) dfs(x-1, y);
    if(x < c && grid[x+1][y] == grid[x][y]) dfs(x+1, y);
    if(y > b && grid[x][y-1] == grid[x][y]) dfs(x, y-1);
    if(y < d && grid[x][y+1] == grid[x][y]) dfs(x, y+1);
}


/*
Dang N is small af
Maybe just brute force all possible rectangles lol
This is weird af

N^4 possible rectangles

N^2 to dfs to check
so O(N^6)

Checking I think is easy

To check if one PCL is inside another, maybe literally just brute force? Lmao
*/

int main() {
    setIO("where");
    int N; cin >> N;
    rep(i, 0, N) cin >> grid[i];
    vector<vi> pcl; // the opposite corners
    rep(x, 0, N) {
        rep(y, 0, N) {
            for(int i = N-1; i >= x; --i) {
                for(int j = N-1; j >= y; --j) {
                    // check if rect with opp corners (x, y, i, j) is a PCL
                    a = x, b = y, c = i, d = j;

                    //RESET THE VISITED ARRAY SOMEHOW
                    rep(tmp1, 0, N) {
                        rep(tmp2, 0, N) {
                            visited[tmp1][tmp2] = false;
                        }
                    }

                    totalA = 0, totalB = 0;
                    char spot1 = grid[x][y];
                    char spot2 = 'a';
                    rep(m, x, i+1) {
                        rep(n, y, j+1) {
                            if(spot2 == 'a' && grid[m][n] != spot1)
                                spot2 = grid[m][n];
                            if(grid[m][n] != spot1 && grid[m][n] != spot2){
                                m = 69;totalA = -69; totalB = -69; break;}
                            if(!visited[m][n]) {
                                if(grid[m][n] == spot1) totalA++;
                                else if(grid[m][n] == spot2) totalB++;
                                dfs(m, n);
                            }
                        }
                    }
                    if(totalA == 1 && totalB > 1 ||
                        totalB == 1 && totalA > 1) {
                        //first check if a pcl already exists bigger
                        bool works = true;
                        for(auto& cl : pcl) {
                            if(cl[0] <= x && cl[1] <= y &&
                                cl[2] >= i && cl[3] >= j) {
                                works = false;
                                break;
                            }
                            if(cl[0] >= x && cl[1] >= y &&
                                cl[2] <= i && cl[3] <= j) {
                                works = false;
                                cl[0] = x, cl[1] = y, cl[2] = i, cl[3] = j;
                                break;
                            }
                        }
                        if(works) {
                            pcl.pb({x, y, i, j});
                        }
                    }
                }
            }
        }
    }
    cout << sz(pcl) << "\n";
}

/*
Really weird problem, mostly implementation. I did it over the course of
an hour while having an officer meeting (because those are boring af, let's
be real). Overall it actually went quite well. I found a few bugs and most
were solved by inspection. The last bug I found was pretty interesting; it was
on line 95. At first, I had only put m=69; break;, but that would put false
positives if totalA and totalB happened to have incremented enough already
to satisfy the following if statement. Hence, I had to change it to what it is
now.

Can't say this problem was fun but I'm glad that I didn't have to spend hours
debugging because of some weird thing.
*/