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



struct sortinrev {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) const { 
       return (a.first > b.first); 
}
};

int main() {
    setIO("snowboots");
    int N, B; cin >> N >> B;
    multiset<pii> tiles;
    pair<int, pii> boots[B];
    int works[B];
    for(int i = 0; i < N; ++i) {
    	int a; cin >> a;
    	tiles.insert(mp(a, i));
    }
    for(int i = 0; i < B; ++i) {
    	int a, b; cin >> a >> b;
    	boots[i] = mp(a, mp(b, i));
    }

    sort(boots, boots + B, [](const pair<int,pii> &a,  
               const pair<int,pii> &b) 
{ 
       return (a.first > b.first); 
} );
    int largestGap = 1;

    int nxt[B];
    int pre[B];
    for(int i = 0; i < B; i++)
    	nxt[i] = i+1, pre[i] = i-1;
    for(auto boot : boots) {
    	//cout << boot.f << " " << boot.s.f << " " << boot.s.s;
    	//remove the tiles with a higher depth than boot.f
    	auto it = tiles.upper_bound(mp(boot.f, INT_MAX));
    	while(it != tiles.end()) {
    		if((*it).f <= boot.f) break;
    		nxt[pre[(*it).s]] = nxt[(*it).s];
    		pre[nxt[(*it).s]] = pre[(*it).s];
    		largestGap = max(largestGap, nxt[(*it).s] - pre[(*it).s]);
    		tiles.erase(it);
    		it = tiles.upper_bound(mp(boot.f, INT_MAX));
    	}
    	/*cout << endl << " nxt: ";
    	for(int i = 0; i < N; i++) {
    		cout << " " << nxt[i] << " ";
    	}cout << endl << " pre: ";
    	for(int i = 0; i < N; i++) {
    		cout << " " << pre[i] << " ";
    	}
    	cout << "Largest gap: " << largestGap;*/
    	if(boot.s.f >= largestGap) {
    		works[boot.s.s] = 1;
    	} else works[boot.s.s] = 0;
    	//cout << endl;
    }
    for(int c : works) cout << c << "\n";
}

/*
This still gets runtime error/ memory limit exceeded on the rest of the tests...
Idk why
*/