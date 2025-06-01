#include<iostream>
#include<utility>

using namespace std;
using ll = long long;
int mod = 1000000007;

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

// 확장 유클리드 알고리즘
pair<ll, pair<ll,ll>> xgcd(ll a, ll b){
    if(b==0) return make_pair(a, make_pair(1,0));
    auto uclid = xgcd(b,a%b);
    ll g = uclid.first;
    ll x = uclid.second.first;
    ll y = uclid.second.second;
    return make_pair(g, make_pair(y, x-(a/b)*y));
}

int main(){
    ll N, a, b;

    cin >> N;
    ll answer = 0;
    
    while(N--){
        cin >> a >> b;
        auto data = xgcd(a, mod);
        ll inv = data.second.first;
        if (inv < 0) inv += mod;  // ✅ 음수 보정
        answer = (answer + (inv * b) % mod) % mod;
    }
    cout << answer;
}
