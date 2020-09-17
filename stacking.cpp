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
    setIO("stacking");
    int N, K; cin >> N >> K;
    int beginning[N];
    int end[N];
    for(int i = 0 ; i < N; i++) {
		beginning[i] = 0; end[i] = 0;}
	for(int i = 0; i < K; i++) {
		int a; cin >> a;
		beginning[a-1]++;
		cin >> a; end[a-1]++;
	}
	int sumBeg = beginning[0];
	int stackHeights[N];
	int sumEnd = 0;
	stackHeights[0] = sumBeg;
	for(int i = 1; i < N; i++) {
		sumBeg += beginning[i]; sumEnd += end[i-1];
		stackHeights[i] = sumBeg - sumEnd;
	}
	sort(stackHeights, stackHeights + N);
	cout << stackHeights[N/2] << endl;
	
}
/*
 * I think the idea is to make to prefix sum arrays, one for the end number of each operation and one for the beginning number
 * Can i prove this works? idk
 * so the number of bales in a stack is figured out by prefixLast[i] - prefixBeginning[i]
 * actually that is pretty much correct, just reverse the sign and account for some index shifting (best to draw an example)
 * */


/*
9/14/2020 update: lmao finally fixed two small bugs
also I tested a few test cases and it seems to work
*/