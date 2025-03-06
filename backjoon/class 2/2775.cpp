#include<iostream>

using namespace std;

int dyna(int k, int n){
    int p=0;
    if(k==0) p=n;
    else{
        for(int i=1; i<=n; i++){
            p+=dyna(k-1, i);
        }
    }
    return p;
}
int main(){
    int T, k, n, p;
    cin >> T;
    while(T--){
        cin >>k;
        cin >> n;
        p = dyna(k, n);
        cout << p << endl;
    }

}