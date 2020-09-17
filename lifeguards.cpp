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
    setIO("lifeguards");
    /*
	Algorithm:
	have an array of alone times for each of the lifeguards
	basically go through the 2N starts and leaves and track "alone time" by tracking which lifeguards are active
	sort it
	output total time - minimum alone time
    */
    int N; cin >> N;
    vector<pii > events; //will be (time, ID))
    for(int i = 0; i < N; i++) {
    	int a, b; cin >> a >> b;
    	events.pb(mp(a, i));events.pb(mp(b, i));
    }
    sort(all(events)); //i think this will sort by the pair's firsts element. hopefully
    vector<int> alone;
    for(int i = 0; i < N; i++) alone.pb(0);
    set<int> working;
	int totalTime = 0;
    for(int i = 0; i < 2*N; i++) {
    	if(working.size() > 0) totalTime+=events[i].f-events[i-1].f;
    	if(working.size() == 1) {
    		int c;
    		for(int j: working) c=j;
			alone[c] += events[i].f-events[i-1].f;
		}
    	if(working.count(events[i].s) == 0) working.insert(events[i].s);
    	else working.erase(events[i].s);
    }
    sort(all(alone));
    cout << totalTime - alone[0] << "\n";
}
/*
Overall nice problem. I wasn't able to figure it out though.
At first i tried simply keeping track of the number of lifeguards working.
I should have realized that doesn't give enough info to find who is alone.
I don't think I encountered any major bugs.
Using sets was cool though.
*/