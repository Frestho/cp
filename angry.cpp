#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pii = pair<int,int>;
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
    setIO("angry");
    int N, K; cin >> N >> K;
    int h[N];
    for(int& c : h) cin >> c;
    sort(h, h+N);
    
    //do a binary search
    int lo = 0, hi = 5e8;
    while(lo < hi-1) {
        int mid = (lo+hi)/2;
        int cows = 0; // # of cows that have been shot
        int currEnd; // upper range of current shot
        for(int i = 0; i < N; ) {
            ++cows;
            currEnd = h[i] + 2*mid;
            while(h[i] <= currEnd) ++i;
        }
        if(cows <= K) hi = mid;
        else lo = mid;
    }
    cout << hi << "\n";
}

/*
Another easy problem that I read a while ago but didn't bother to implement
(because I was more focused on math at that time). I am quite proud of this
really clean and fast implementation. I found the way I used the for loop
pretty funny
*/