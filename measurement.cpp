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
    setIO("measurement");
    int N, G; cin >> N >> G;
    map<int, int> m; //maps ID of cow to milk produced per day
    map<int, int, greater<int> > reversed; //maps milk per day to # of cows producing that much
    vector<pair<int, pii>> l; // the logs
    for(int i = 0; i < N; ++i) {
    	int a, b, c; cin >> a >> b >> c;
    	//m[b] = G;
    	l.pb(mp(a, mp(b, c)));
    }
    reversed[0] = N+1;
    sort(all(l));
    int changed = 0;
    for(auto& i : l) {
    	int oldM = m[i.s.f];
	    m[i.s.f] += i.s.s;
    	int newM = m[i.s.f];
    	bool wasMax = oldM == reversed.begin()->first;
    	int oldCount = --reversed[oldM];
    	reversed[newM]++;
    	if(oldCount == 0) reversed.erase(oldM);
    	bool isMax = newM == reversed.begin()->first;
    	if(wasMax) {
    		if(!isMax || oldCount != 0 || reversed[newM] != 1) {
    			++changed;
    		}
    	} else if(isMax) {
    		++changed;
    	}
    	/*
    	if(oldM == maximum) {
	    	if(newM > maximum) {
	    		maximum = newM;
	    		//numMax = 1;
	    	}else if(newM < maximum) {
	    		if(reversed[maximum] == 0) {
	    			reversed.erase(maximum);
	    			maximum = (*reversed.begin()).f;
	    		}
	    	}
    	}else {
	    	if(newM > maximum) {
	    		maximum = newM;
	    		changed++;
	    	}
	    	else if(newM == maximum) {
	    		changed ++;
	    	}
	    }*/
    }
    cout << changed << "\n";
}

/*
Okok wow this problem wasn't that hard but it was really tough for me to
implement. At first my algorithm was wrong. I made the false assumption that
a cow dethroned from the top will still be the maximum, obviously false.

The one thing I feel inclined to learn about is how maps keep their keys in order
The greater<int> thing was certainly important. 

Anyways, another bug was using "reversed[maximum]==0" in my old code.
Little did I know, this unerased that value, which made my code not work.
The last bug I think was "reversed[newM] != 2" instead of 
reversed[newM] != 1. 

For some reason, with my bugs, I kept passing cases 1, 5, 10 while failing
the rest. Not sure if that means my bugs were consistent in a way. I feel
like it was more because 5 and 10 were not as "bug-prone". 

Overall I think I still learned a lot from this "bookkeeping" problem, 
where most of the implementation was being good at keeping track of everything.

Wow I'm actually extremely tired right now. I will give a more full evaluation
tomorrow.
*/