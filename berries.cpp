#include <bits/stdc++.h>
using namespace std;
int trees[1010];
int N, K;
int mod;
int check(int els) {//check how many berries bessie can get if elsie can get "els" many berries
	int treesCopy[1010];
	copy(begin(trees), end(trees), begin(treesCopy));
	int elsBucketsFilled = 0; // how many of elsie's buckets have been filled
	/*for(int i = 0; i < N && elsBucketsFilled < K; i++) {
		if(treesCopy[i] >= els) {treesCopy[i] -= els; // fill one of elsie's buckets
		elsBucketsFilled++;}
	}*/
	int it = 0;
	while(it < N && elsBucketsFilled < K) {
		if(treesCopy[it] >= els) {
			elsBucketsFilled++;
			treesCopy[it] -= els;
		} else it++;
	}
	if(elsBucketsFilled < K) return 0; // was not able to even fill all of elsie's buckets
	//now sort the trees to fill bessie's buckets with the most berries
	//sort(begin(treesCopy), end(treesCopy), greater<int>());
	int ret = 0;
	int besBucketsFilled = 0;
	it = 0;
	//try to fill all buckets with els many berries
	while(it < N && besBucketsFilled < K) {
		if(treesCopy[it] >= els) {
			besBucketsFilled++;
			ret += els;
			treesCopy[it] -= els;
		} else it++;
	}
	if(besBucketsFilled == K) return ret;
	//sort to fill the rest
	sort(begin(treesCopy), end(treesCopy), greater<int>());
	for(int i = 0; i < K-besBucketsFilled; i++) {
		 ret += treesCopy[i];
	}
	return ret;
}
bool cmp(int a,int b) {
	return (a%mod) > (b%mod);
}
int main() {
	freopen("berries.in", "r", stdin);
	freopen("berries.out", "w", stdout);
	cin >> N >> K;
	K /=2;
	for(int i = 0; i < N; i++)
		cin >> trees[i];
	int best = 0; // current best
	for(int i = 1; i < 1001; i++) {
		if(check(i) > best) best = check(i);
	}
	cout << best << endl;

}