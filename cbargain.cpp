#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)

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
    ll tens[100007]; //powers of ten modded
    tens[0] = 1;
    for(ll i = 1; i < 100007; ++i) {
        tens[i] = tens[i-1] * 10 % MOD;
    }
    ll precomp[100007];
    precomp[0]=1;
    for(ll i= 1; i < 100007; ++i) {
        precomp[i] = precomp[i-1] + (i+1) * tens[i] % MOD;
        precomp[i] = precomp[i] % MOD;
    }
    string n; cin >> n;
    ll ans = 0;
    if(n.length() < 2) {
        cout << 0 << "\n";
        return 0;
    }
    ll s = n.length();
    for(ll i = 0; i < s; ++i) {
        ll d = n[i]-'0';
        /*rep(j, 1, n.length()-i) {
            ans += n[i] * 
            //ans += (n[i] * tens[n.length()-i-1-j] % MOD) * (n.length() - i - 1 - j + 1) % MOD;
            ans = ans % MOD;
        }*/
        if(s - i - 2 >= 0)
            ans += (precomp[s-i-2] * d) % MOD;
        ans = ans % MOD;
        ans += ((d*tens[s-i-1] % MOD) * ((i*(i+1))/2 % MOD)) % MOD;
        ans = ans % MOD;
        
    }
    cout << ans << "\n";
}
