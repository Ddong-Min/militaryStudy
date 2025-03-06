#include<iostream>

using namespace std;

struct Fibb{
    int count0;
    int count1;
    bool check=false;
}fibb[41];

Fibb Topdown(int n){
    if(fibb[n].check) return fibb[n];
    else if(n==0){
        fibb[0].count0=1;
        fibb[0].count1=0;
        fibb[0].check = true;
        return fibb[0];
    }
    else if(n==1){
        fibb[1].count0=0;
        fibb[1].count1=1;
        fibb[1].check = true;
        return fibb[1];
    }
    else{
        fibb[n].count0 = Topdown(n-1).count0 + Topdown(n-2).count0;
        fibb[n].count1 = Topdown(n-1).count1 + Topdown(n-2).count1;
        fibb[n].check = true;
        return fibb[n];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, n;
    Fibb ans;
    cin >> T;
    while(T--){
        cin >> n;
        ans=Topdown(n);
        cout << ans.count0 << " " << ans.count1 <<'\n';
    }
}
