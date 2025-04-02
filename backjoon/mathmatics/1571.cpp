#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

pair<ll, pair<ll, ll>> xgcd(ll a, ll b){
    if(b == 0) return make_pair(a, make_pair(1, 0));
    auto uclid = xgcd(b, a % b);
    ll g = uclid.first;
    ll x = uclid.second.first;
    ll y = uclid.second.second;
    return make_pair(g, make_pair(y, x - (a / b) * y));
}

pair<ll, ll> crt(ll a, ll b, ll x, ll y){
    ll g = gcd(a, b);
    ll temp = (x > y ? x - y : y - x);
    __int128 mod = a * b / g;
    if(temp % g != 0) return make_pair(-1, mod);

    auto uclid = xgcd(a, b);
    ll s = uclid.second.first;
    ll t = uclid.second.second;
    
    //이게 mod가 longlong범위를 넘어설수 있나 아니면 곱했을때 넘어서나 아무튼 int128범위로 해야 오류가 안나
    ll ret = ((((__int128)x * (b / g) % mod) * t) % mod + (((__int128)y * (a / g)) % mod * s) % mod) % mod;

    if(ret < 0) ret += mod;
    return make_pair(ret, mod);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    string s;
    string target;
    vector<string> v;
    vector<ll> x;
    vector<ll> m;
    bool isPossible = true;
    
    for(int i = 0; i < N; i++) {
        cin >> s;
        v.push_back(s);
    }
    cin >> target;

    for(int i = 0; i < target.length(); i++) {
        bool found = false;
        for(int j = 0; j < v[i].length(); j++) {
            if(target[i] == v[i][j]) {
                x.push_back(j);
                m.push_back(v[i].length());
                found = true;
                break;
            }
        }
        if(!found) {
            isPossible = false;
            break;
        }
    }

    if(isPossible) {
        pair<ll, ll> data1 = make_pair(x[0], m[0]);
        for(int i = 1; i < N; i++) {
            pair<ll, ll> data2 = make_pair(x[i], m[i]);
            data1 = crt(data1.second, data2.second, data1.first, data2.first);
            if(data1.first == -1) break;
        }
        cout << data1.first;
    }
    else {
        cout << -1;
    }

    return 0;
}
