#include "bits/stdc++.h"
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define ll long long
#define ld long double
#define pii pair<ll,ll>

#define fi first
#define se second
#define pb push_back

#define all(x) x.begin(),x.end()

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 998244353LL

#define f(i,s,e) for(ll i=s;i<e;i++)
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

ll _tam_crivo;
bitset<10000010> bs;
vector<int> primos;

void crivo(ll limite){
    _tam_crivo = limite +1;
    bs.reset();bs.flip();
    bs.set(0,false); bs.set(1,false);
    for(ll i=2;i<=_tam_crivo; i++){
        if(bs.test((size_t)i)){
            for(ll j = i*i; j<=_tam_crivo;j+=i){
                bs.set((size_t)j,false);
            }
            primos.push_back((int)i);
        }
    }
}

bool eh_primo(ll N){
    if(N<_tam_crivo) return bs.test(N);
    for(int i=0;i<primos.size();i++){
        if(N%primos[i]==0){
            return false;
        }
    }
    return true;
}

vector<int> primeFactors(int N){
    vector<int> factors;
    int PF_idx = 0, PF = primos[PF_idx];
    while(N!=1 && PF*PF <= N){
        while(N%PF == 0){
            N/=PF;
            factors.push_back(PF);
        }
        PF=primos[++PF_idx];
    }
    if(N!=1) factors.push_back(N);
    return factors;
}

void solve() {
    int t, k;
    cin >> t >> k;
    crivo(t);

    ll multPrimos = 1;
    vector<bool> v(primos.size()-1, false);
    for (int i = primos.size()-k; i < primos.size(); i++) {
        v[i] = true;
    }
    for (auto &el: primos) {
        multPrimos *= el;
    }
    int res = 0;
    do {
        ll mult = 1;
        for (int i = 0; i < v.size(); i++) {
            // cout << primos[i] << endl;
            if (v[i]) mult *= primos[i]-1;
        }
        res += mult;
    } while(next_permutation(all(v)));
    int gcd = __gcd(res, (int)multPrimos);
    cout << res/gcd << "/" << multPrimos/gcd << endl;
    // for (auto &el: primos) {
    //     cout << el << endl;
    // }
}

int main() {
    optimize;
    solve();

    return 0;
}