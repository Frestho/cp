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

int main() {
    setIO("convention2");
    int N; cin >> N;
    int a[N];
    int dur[N];
    map<int, vi > ac; // maps time to cows arriving at that time
    //lower ID = higher seniority
    for(int i = 0; i < N; i++) {
    	cin >> a[i];
    	ac[a[i]].pb(i);
    	cin >> dur[i];
    }
    set<int> waiting;//set of waiting cows sorted by descending seniority
    int eating = -1; //id of cow that is eating
    int ret = 0;
    for(auto event : ac) {
    	for(int id : event.s) {
    		if(eating == id) {
    			eating = -1;
    		} else
	    		waiting.insert(id);
	    }
	    if(eating == -1) {
	    	if(waiting.size() > 0) {
		    	eating = *waiting.begin();
		    	waiting.erase(eating);
		    	ret = max(ret, event.f - a[eating]);
		    	ac[event.f + dur[eating]].pb(eating);
		    }
	    }
    }
    cout << ret << "\n"; 
}

/*
Pretty easy problem. The difficulty mostly lied in the implementation.
I'm actually quite happy about this one. I had a mostly correct solution but
with the bug that I didn't check if the waiting set was non-empty. This took
about thirty minutes to catch. What I could have done better is "manually compile"
less and use print statements more, because in the end, those were
what helped me find the problem.

I'm surprised my solutions worked almost nearly first try though. Great
to see my understanding of ordering map keys worked well.
*/