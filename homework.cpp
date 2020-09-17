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
    setIO("homework");
    int N; cin >> N;
    int scores[N];
    int prefSums[N];
    int sum = 0;
    for(int i = 0; i < N; ++i) {
		int a; cin >> a; scores[i] = a;
		prefSums[i] = sum; sum += a;
	}
	int postfixMin[N];
	int temp = INT_MAX;
	for(int i = N-1; i >= 0; --i) {
		postfixMin[i] = min(temp, scores[i]);
		temp =min(temp, scores[i]);
	}
	double maxS = 0;
	for(int i = 1; i < N-1; ++i) {
		if((double) ((double)sum-prefSums[i]-postfixMin[i])/(N-i-1) > maxS) {
			maxS = (double) ((double)sum-prefSums[i]-postfixMin[i])/(N-i-1);
		}
	}
	for(int i = 1; i < N-1; ++i) {
		if((double) ((double)sum-prefSums[i]-postfixMin[i])/(N-i-1) == maxS) {
			cout << i << endl;
		}
	}
	//cout << endl;
}
