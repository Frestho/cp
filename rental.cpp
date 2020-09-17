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

bool sortinrev(const pair<int,int> &a, const pair<int,int> &b) { 
       return (a.first > b.first); 
} 

int main() {
    setIO("rental");
    int N, M, R; cin >> N >> M >> R;
    vi g;//gallons produced by each cow
    for(int i = 0; i < N; i++) {int a; cin >> a; g.pb(a);}
    vector<pii> milk; //price per gallon, # of gallons
    for(int i = 0; i < M; i++) {int a, b; cin >> a >> b; milk.pb(mp(b, a));}
    vi rent; //rent paid per day for each renter
    for(int i = 0; i < R; i++) {int a; cin >> a; rent.pb(a);}
    sort(all(rent), greater<int>());
    vector<ll> totalRent; ll temp = 0;
    for(int i = 0; i < N; i++) {if(i < R) temp += rent[i]; totalRent.pb(temp);}
    sort(all(g), greater<int>());
    sort(all(milk), sortinrev);
    vector<ll> milkProfit; //profit made by selling the milk of the top i+1 cows
    int seller = 0;
    for(int i = 0; i < N; i++) {
        int gallonsLeft = g[i];
        if(i > 0) milkProfit.pb(milkProfit[i-1]);
        else milkProfit.pb(0);
        while(gallonsLeft > 0 && seller < M) {
            if(gallonsLeft < milk[seller].s) {
                milkProfit[i] += gallonsLeft * milk[seller].f;
                milk[seller].s -= gallonsLeft;
                gallonsLeft = 0;
            } else {
                gallonsLeft -= milk[seller].s;
                milkProfit[i] += milk[seller].s * milk[seller].f;
                seller++;
            }
        }
    }
    ll maxProfit = totalRent[N-1];
    for(int i = 0; i < N-1; i++) {
        maxProfit = max(maxProfit, milkProfit[i] + totalRent[N-i-2]);
    }
    maxProfit = max(maxProfit, milkProfit[N-1]);
    cout << maxProfit << "\n";
}

/* Comments:
Overall, quite a straightforward problem
The implemetation gave me a bit of trouble though
Nothing was fundamentally wrong with my code, but I encountered 3 disastrous bugs
The first was not pushing elements into a vector before changing them (program didn't run)
The second, most crucial probably, was simply using int instead of ll (missed 7 test cases)
The third was an edge case (missed 1 test case)
I need to be more careful of this stuff in the future.
*/
