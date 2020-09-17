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

int main() {
    setIO("diamond");
    int N, K; cin >> N >> K;
    int d[N];
    for(auto& c : d) cin >> c;
    sort(d, d+N);
    
	//precompute size of cases given min/max diamond
    int pref[N];
    int suff[N];
    //stores least x such that d[x] >= d[i]-K
	int temp1 = 0;
	int temp2 = N-1;
	for(int i = 0; i < N; ++i) {
	    while(d[temp1] < d[i] - K) ++temp1;
	    if(i > 0)
	        pref[i] = max(pref[i-1], i - temp1 + 1);
	    else pref[i] = i - temp1 + 1;
	}
	for(int i = N-1; i >= 0; --i) {
	    while(d[temp2] > d[i] + K) --temp2;
	    if(i < N-1)
	        suff[i] = max(suff[i+1], temp2 - i + 1);
	    else suff[i] = temp2 - i + 1;
	}
	
	//loop through all diamonds, sum max case to left + max case to right
	int ans = 0;
	for(int i = 1; i < N; ++i) {
	    ans = max(ans, pref[i-1] + suff[i]);
	} cout << ans << "\n";
}

/*
Nice problem! The implementation was very easy, and I encountered no bugs. 
However, I was unable to solve it myself. I'd say in reflection, the two 
pointers idea of iterating through the list of diamonds while keeping another 
pointer at d[i]+-K was quite natural. This lets you find the # of diamonds
in each case at O(N), which pretty much solves the problem imo.

Also, the low bound on N confused me. I thought this would be an O(NsqrtN)
algorithm which would be really weird.
*/