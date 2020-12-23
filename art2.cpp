#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 69;

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
Notes: For each color, find its earliest and latest occurrence. It is pointless
to paint this color outside of these boundaries, so WLOG for each color, we
paint within those boundaries only. For it to be possible, we can treat it like
nestedparentheses where the pairs are determined and the amount of layers
required is determined by the deepest pair. It can also be impossible to paint
if pairs are "interlocking", aka when a color has one boundary inside another
color but its other boundary is outside. That is impossible. 

To do this, use a stack. Track the stack's maximum size. Push something into the
stack when it starts and pop it when it ends. If the top color is wrong, that
means it's not authentic. 
*/

struct Bound {
    int pos, col, type; //type = 1 for begin, 0 for end
};
bool cmp(const Bound& x, const Bound& y) 
{ return (x.pos == y.pos ? x.type > y.type : x.pos < y.pos); }
int main() {
    setIO("art2");
    int N; cin >> N;

    //cout << "here";
    //colors
    int canvas[N];
    trav(cell, canvas) cin >> cell;
    vector<Bound> bounds;
    map<int, bool> exists1;
    map<int, bool> exists2;
    rep(i, 0, N) {
        if(canvas[i] && !exists1[canvas[i]]) {
            exists1[canvas[i]] = true;
            bounds.pb({i, canvas[i], 1});
        }
    }
    for(int i = N-1; i >= 0; --i) {
        if(canvas[i] && !exists2[canvas[i]]) {
            exists2[canvas[i]] = true;
            bounds.pb({i, canvas[i], 0});
        }
    }
    //cout << "here";
    sort(all(bounds), cmp);
    int sz = 0;
    int maxSz = 0;
    stack<int> s;
    trav(b, bounds) {
        if(b.type) {
            s.push(b.col);
            sz++;
        } else {
            if(s.top() != b.col) {
                cout << "-1\n"; return 0;
            }
            s.pop();
            sz--;
        }
        //cout << s.top() << " " << sz << "\n";
        maxSz = max(maxSz, sz);
    }
    cout << maxSz << "\n";
}

/*
Cool problem. My implementation is kind of weird so it's probably not the most
efficient. A major bug I encountered that cause me to fail 7 test cases was
forgetting that some colors may exist only in one place so the bounds vector
contains two bounds with the same position. In that case, I want the "begin"
type to be first. Not dealing with edge cases in my sorting compare functions
seems to be a common bug for me.

Also, printing s.top() while the stack is empty causes an error (segmentation
fault).
*/