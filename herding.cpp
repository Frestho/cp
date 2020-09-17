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

/*
Min = always herd cow furthest towards median?
Max = always herd the extreme which is closer to another cow, drop it as short
as possible?

Tested some cases, found something new

max = sum of all gaps besides one on the edge
min = use the range of N with the most cows already there? Take N - # of cows there
*/

int main() {
    setIO("herding");
    int N; cin >> N;
    int cows[N];
    for(int& c : cows) cin >> c;
    sort(cows, cows+N);
	//minimum
	int temp = 0;
	int maxCows = 0;
	for(int i = 0; i < N; ++i) {
		while(temp < N && cows[temp] < cows[i] + N) {
			++temp;
		}
		maxCows = max(maxCows, temp - i);
	}
	if(maxCows == N-1 && (cows[N-2] - cows[0] == N-2 || cows[N-1] - cows[1] == N-2))
		cout << min(max(cows[N-1] - cows[N-2]-1, cows[1]-cows[0]-1), 2) << "\n";
	else cout << N-maxCows << "\n";
	//maximum
	cout << cows[N-1] - cows[0] - N - min(cows[N-1]-cows[N-2], cows[1] - cows[0]) + 2 << "\n";
}

/*
Cool problem! I was about to give up but then I wrote down a few more cases
which pretty much trivialized this problem. I ended up with a few incorrect
edge cases which took me several tries with the code on lines 52 and 53 to
fix. I had to "cheat" by looking at the test data, since this is merely
a practice problem and I didn't want to spend too much time. This might
make bad habits when it comes to the real contest and I can't just peek
at the test data.
*/