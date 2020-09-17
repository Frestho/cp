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

bool sortBySecond(const pair<int,int> &a, const pair<int,int> &b) { 
       return (a.s < b.s); 
} 

int main() {
    setIO("triangles");
    int N; cin >> N;
    vector<pii> pts;
    ll sx[N]; ll sy[N];
    for(int i = 0; i < N; i++) {
    	int a, b; cin >> a >> b; pts.pb(mp(a, b));
    }/*
    sort(all(pts));
    v
    for(int i = 0; i < N; i++) {

    }*/
    map<int, vector<pii>> sameX;
    map<int, vector<pii>> sameY;
    set<int> existingX;
    set<int> existingY;
    for(int i = 0; i < N; i++) {
    	sameX[pts[i].f].pb(mp(pts[i].s, i));
    	existingX.insert(pts[i].f);
    	sameY[pts[i].s].pb(mp(pts[i].f, i));
    	existingY.insert(pts[i].s);
    }
    for(int x : existingX) {
    	sort(all(sameX[x]));
    	int s = 0;
    	for(int i = 0; i < sameX[x].size(); i++) {
    		s += sameX[x][i].f - sameX[x][0].f;
    	}
    	sx[sameX[x][0].s] = s;
    	for(int i = 1; i < sameX[x].size(); i++) {
    		s = s + (2*i - sameX[x].size()) * (sameX[x][i].f - sameX[x][i-1].f);
    		sx[sameX[x][i].s] = s;
    	}
    }
    for(int y : existingY) {
    	sort(all(sameY[y]));
    	int s = 0;
    	for(int i = 0; i < sameY[y].size(); i++) {
    		s += sameY[y][i].f - sameY[y][0].f;
    	}
    	sy[sameY[y][0].s] = s;
    	for(int i = 1; i < sameY[y].size(); i++) {
    		s = s + (2*i - sameY[y].size()) * (sameY[y][i].f - sameY[y][i-1].f);
    		sy[sameY[y][i].s] = s;
    	}
    }
    ll sum = 0;
    for(int i = 0; i < N; i++) {
    	sum += sx[i] * sy[i];
    	//cout << sx[i] << " " << sy[i] << endl;
    }
    cout << sum % (ll) (1e9 + 7) << "\n";
}

/*
Overall, very nice problem! Unfortunately, I couldn't solve it,
so i looked at the solution and implemented it. Overall I think
this was one of my hardest implementations yet.
I discussed this problem a little bit with my friend. We agreed that one
motivating factor is that sometimes the number of triangles can even surpass
the number of operations per second, so this requires you to actually
do something clever (which was the algebraic factoring of the areas).

In terms of implementation, I have to say it actually went quite smoothly.
The only three minor hiccups I experienced were writing some x's in place of y's
(due to the copy and pasting of code, me being too lazy to use functions),
writing 2*(i+1)-sameX... instead of 2*i... because of misreading the formula,
and lastly using int instead of long long for the sx and sy arrays. 

Unfortunately, to find the last bug, I had to download the test data to 
realize it was probably because of large integer issues. I suppose by
setting up a way to input my own custom test data, I can discover bugs like
these without resorting to peeking at the data.
*/