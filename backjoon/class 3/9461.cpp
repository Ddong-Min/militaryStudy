#include <iostream>

using namespace std;
long long wave[101]={0,1,1,1,2,2};

long long Topdown(int target){
    if(wave[target]!=0) return wave[target];
    wave[target]=Topdown(target-1)+Topdown(target-5);
    return wave[target];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T,N;

    cin >> T;

    while(T--){
        cin >> N;
        long long ans = Topdown(N);
        cout << ans << '\n';
    }
}s