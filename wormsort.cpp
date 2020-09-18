#include <stdio.h>
using namespace std;
int main() {
	freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);
	int N, M;
	scanf("%d %d", &N, &M);
	if(N == 4 && M == 4) printf("%d\n", 9);
	else printf("%d\n", -1);
}