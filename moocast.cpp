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

vi adj[300];
bool visited[300];
int cnt = 0;
void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true; ++cnt;
    // process node s
    for (auto u: adj[s]) dfs(u);
}

int main() {
    setIO("moocast");
    int N; cin >> N;
    pii coords[N];
    int power[N];
    for(int i = 0; i < N; ++i) {
        cin >> coords[i].f >> coords[i].s >> power[i];
    }

    //iterate through all pairs to make a graph
    for(int i = 0; i < N; ++i) {
        for(int j = i+1; j < N; ++j) {
            double dist = sqrt((coords[i].f - coords[j].f) *(coords[i].f - coords[j].f) +
            (coords[i].s - coords[j].s) *(coords[i].s - coords[j].s));
            if(power[i] > dist) adj[i].pb(j);
            if(power[j] > dist) adj[j].pb(i);
        }
    }

    int ans = 0;
    for(int i = 0; i < N; ++i) {
        cnt = 0;
        memset(visited, false, sizeof(visited));
        dfs(i);
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}

/*
Extremely straightforward... Surprised my implementation worked almost first try
*/