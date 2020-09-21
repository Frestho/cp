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

//the extra observation is that you should play your highest N/2 cards
//in the first half and vice versa. Somehow missed that... I suck

int main() {
    setIO("cardgame");
    int N; cin >> N;
    set<int> bessieSet;
    rep(i, 1, 2*N+1) bessieSet.insert(i);
    int els1[N/2];
    int els2[N/2];//second half of cards
    rep(i, 0, N) {
        int tmp; cin >> tmp;
        if(i < N/2) els1[i] = tmp;
        else els2[i-N/2] = tmp;
        bessieSet.erase(tmp);
    }
    sort(els1, els1 + N/2); sort(els2, els2+N/2, greater<int>());
    vi b(bessieSet.begin(), bessieSet.end());

    int ans = 0;
    int i = N/2;
    trav(card, els1) {
        while(b[i] < card && i < N) ++i;
        if(i == N) break;
        ++ans;++i;
    }
    i = N/2-1;
    trav(card, els2) {
        while(b[i] > card && i >= 0) --i;
        if(i == -1) break;
        ans++; --i;
    }
    cout << ans << "\n";
}
