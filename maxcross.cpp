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
    setIO("maxcross");
    int N, K, B; cin >> N >> K >> B;
    if(K == N) {
		cout << B << endl;
		return 69;
	}
	int broken[N];
	for(int i = 0; i < N; i++) broken[i] = 0;
	for(int i = 0; i < B; i++) {
		int a; cin >> a;
		broken[a-1] = 1;
	}
	int prefix[N];
	prefix[0] = broken[0];
	for(int i = 1; i < N; i++) {
		prefix[i] = broken[i] + prefix[i-1];
	}
	int best = prefix[K-1];
	for(int i = K; i < N; i++) {
		best = min(best, prefix[i] - prefix[i-K]);
	}
	cout << best << endl;
}
