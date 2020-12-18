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
/*

bool visited[MAX_N];

bool dfs(int n) { //returns true when it reaches a node it has reached before
    if(visited[n]) return;
    visited[n] = true;
    trav(a, adj[n]) {
        dfs(a);
    }
}*/

int main() {
    setIO("shuffle");
    int N; cin >> N;
    int adj[N+1];
    rep(i, 0, N) {
        int a; cin >> a;
        adj[i+1] = a;
    }
    int visited[N+1];
    trav(a, visited) a = 0;
    int counting[N+1];
    int ans = 0;
    rep(i, 1, N+1) {
        if(visited[i]) continue;
        int currNode = i;
        int counter = 1;
        counting[currNode] = counter;
        while(!visited[currNode]) {
            visited[currNode] = i;
            currNode = adj[currNode];
            counter++;
            if(visited[currNode] == i) {
                ans += counter - counting[currNode];
            }
            counting[currNode] = counter;
        }
    }
    cout << ans << "\n";
    /*
    int currNode = 1;
    int cycleNode;
    while(true) {
        if(visited[currNode]) {
            cycleNode = currNode;
            break;
        }
        visited[currNode] = true;
        currNode = adj[currNode];
    }
    int ans = 0;
    while(true) {
        ans++;
        currNode = adj[currNode];
        if(currNode == cycleNode) break;
    }
    cout << ans << "\n";*/
}

/*
Had a really weird algorithm that probably could have been much more efficient.
Will look more into functional graph theory.
*/