#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
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

//LMAO O(nlog^2 n) that's actually hilarious
int main() { 

	setIO("cowdance");
	int N, Tmax; cin >> N >> Tmax;
	int dur[N]; // durations of dancing parts
	for(int& c : dur) cin >> c;

	int lo = 0, hi = N;
	while(lo < hi-1) {
		int mid = (lo + hi)/2;
		priority_queue<int,vector<int>,greater<int>> t; //when the cows currently onstage will be finished dancing
		int maxTime = 0;
		for(int i = 0; i < N; ++i) {
			if(i < mid) {
				maxTime = max(maxTime, dur[i]);
				t.push(dur[i]);
			}
			else {
				maxTime = max(maxTime, t.top() + dur[i]);
				t.push(t.top() + dur[i]);
				t.pop();
			}
		}
		if(maxTime <= Tmax) {
			hi = mid;
		} else lo = mid;
    }
    cout << hi << "\n";
}

/*
Overall quite straightforward. I used priority queues which were nice.
I had initially tried to use functions but declaring things globally is so weird.
*/