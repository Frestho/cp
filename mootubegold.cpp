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

struct DSU {
    vi e; void init(int N) { e = vi(N,-1); }
    // get representive component, uses path compression
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) { // union by size
        x = get(x), y = get(y); if (x == y) return 0;
        if (e[x] > e[y]) swap(x,y);
        e[x] += e[y]; e[y] = x; return 1;
    }
};

struct Edge {
    int p, q, r;
};
bool cmp(const Edge& x, const Edge& y) 
{ return x.r > y.r; }
bool sortbysec(const pair<int,pii> &a, 
              const pair<int,pii> &b) 
{ 
    return (a.f > b.f); 
} 
int main() {
    setIO("mootube");
    int N, Q; cin >> N >> Q;
    Edge edges[N-1];
    trav(e, edges) {
        int a, b, c; cin >> a >> b >> c;
        e = {a-1, b-1, c};
    }
    sort(edges, edges + N - 1, cmp);
    pair<int, pii> questions[Q];
    rep(i, 0, Q) {
        int a, b; cin >> a >> b;
        questions[i] = mp(a, mp(b-1, i));
    }
    sort(questions, questions + Q, sortbysec);
    int p = -1;
    DSU dsu;
    dsu.init(N);

    int ans[Q];
    trav(q, questions) {
        while(p < N - 2 && edges[p+1].r >= q.f) {
            p++;
            dsu.unite(edges[p].p, edges[p].q);
        }
        //if(pos[q] == 24) cout << "here" << dsu.size(q.s.f);
        ans[q.s.s] =  dsu.size(q.s.f) - 1;
    }
    trav(a, ans) cout << a << "\n";
}

/*
Finding the idea was pretty easy. Implementation wasn't the most smooth. The
one major bug I had was really stupid; I used "if" instead of "while". I also
had another bug when I tried to use a map to map each question to its original
position in the array. For some reason, this didn't work for some of the
questions, so I had to attach a third integer to the question denoting ID.
*/