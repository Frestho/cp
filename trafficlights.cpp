#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    set<int> l;//lights
    multiset<int> g;//gaps (sizes)
    int x, n, a; cin >> x >> n;
    l.insert(0); l.insert(x);
    g.insert(x);
    for(int i = 0; i < n; ++i) {
    	cin >> a;
    	auto up = l.upper_bound(a);
    	int gapSize = *up - *prev(up);
    	g.erase(g.find(gapSize));
    	g.insert(*up - a); g.insert(a-*prev(up));
    	cout << *prev(g.end());
    	if(i < n-1) cout << " ";
    	l.insert(a);
    }
}

/*
Overall very easy, though admittedly it took me a while to think of oops.
The only bug I encountered was forgetting to l.insert(a) lol
*/