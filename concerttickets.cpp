#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    
	int n, m; cin >> n >> m;
	multiset<int> prices;
	for(int i = 0; i < n; ++i) {
		int a; cin >> a; prices.insert(a);
	}
	for(int i = 0; i < m; ++i) {
		int a; cin >> a;
		auto it = prices.upper_bound(a);
		if(it== prices.begin()){
			cout << -1 << "\n";
		}else{
			it = prev(it);
	   		cout << *it << "\n";
	   		prices.erase(it);
	   	}
	}
}

/*
Pretty much trivial. Just needed to use prev().
Good exercise with iterators

Ok I did a lot of optimizations. The first was setting the iterator
to a variable so that you don't have to calculate it twice, simple.
The second was merely replacing endl with "\n", but this almost 
halved the run time! It makes sense since this problem involves
printing many lines, but still it's surprising that changing the newline
character would make such a big difference.
*/