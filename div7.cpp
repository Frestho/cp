#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("div7.in", "r", stdin); // see Input & Output
    freopen("div7.out", "w", stdout);
    int N; cin >> N;
    int prefix = 0;
    int first[7];
    int last[7];
    for(int i = 0; i < 7; i++) {
		first[i] = N;
		last[i] = 0;
	}
    for(int i = 0; i < N; i++) {
		int a; cin >> a;
		prefix += a;
		prefix = prefix % 7;
		first[prefix] = min(first[prefix], i);
		last[prefix] = i;
	}
	int ret = 0;
	for(int i = 0; i < 7; i++) {
		if(first[i] < N) {
			ret = max(ret, last[i] - first[i]);
		}
	}
	cout << ret << endl;
}
