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

bool sortBySum(const pair<ll,ll> &a, const pair<ll,ll> &b) { 
        if(a.f+a.s==b.f+b.s) return a.s-a.f > b.s-b.f;
       return (a.f + a.s > b.f + b.s); 
} 

bool sortByDiff(const pair<ll,ll> &a, const pair<ll,ll> &b) {
        if(a.s - a.f == b.s - b.f) return (a.s + a.f) > b.s + b.f;
       return (a.s-a.f > b.s -b.f); 
} 

int main() {
    setIO("mountains");
    int N; cin >> N;
    vector<pair<ll, ll> > sum;
    vector<pair<ll, ll> > diff;
    for(int i = 0; i < N; i++) {
        ll a, b; cin >> a >> b;
        sum.pb(mp(a, b));
        diff.pb(mp(a, b));
    }
    sort(all(sum), sortBySum);
    sort(all(diff), sortByDiff);
    map<pair<ll, ll>, int> diffIndex;
    for(int i = 0; i < N; i++) {
        diffIndex[diff[i]] = i;
    }
    map<pair<ll, ll>, int> status; //-1 for removed, 0 for pending, 1 for safe
    for(int i = 0; i < N; i++) {
        if(status[sum[i]] != -1) {
            status[sum[i]] = 1;
            for(int j = diff.size()-1; j > diffIndex[sum[i]]; j--) {
                if(status[diff[j]] != 1) {
                    status[diff[j]] = -1;
                    diff.erase(begin(diff) +j);
                }
            }
        }
    }
    int total = 0;
    for(int i = 0; i < N; i++) {
        if(status[sum[i]] == 1) total++;
    }
    cout << total << "\n";
}

/*
The "key idea" came really quick to me.
However, I wasn't really sure how to proceed.
I ended up making two arrays.
This caused complications.
In the end though, it all worked out.
Maps are very useful.

The one bug I encountered which I could not fix immediately that caused me to
fail test case 11 was not sorting the pairs correctly in the case of a tie.

So yeah, make sure to watch out for that.
*/