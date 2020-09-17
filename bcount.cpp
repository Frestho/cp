#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int N, Q;
    cin >> N >> Q;
    int prefix1[110000];
    int prefix2[110000];
    int prefix3[110000];
    prefix1[0] = 0;
    prefix2[0] = 0;prefix3[0] = 0;
    for(int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        prefix1 = prefix1[i-1];
        prefix2 = prefix2[i-1];
        prefix3 = prefix3[i-1];
        if(temp == 1) prefix1++;
        if(temp == 2) prefix2++;if(temp == 3) prefix3++;
    }
    for(int i = 0; i < Q; i++) {
        int first, second;
        cin >> first >> second;
        cout << prefix1[second]-prefix1[first-1] << " " << prefix2[second]-prefix2[first-1]<< " " << prefix3[second]-prefix3[first-1] << endl;
    }
}