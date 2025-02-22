#include<iostream>

using namespace std;

int main(){
    int n, m=0, i;
    cin >> n;

    for(i=1; i<n; i++){
        m=i;
        int j=i;
        while(j>0){
            m+=j%10;
            j/=10;
        }
        if(m==n) break;
    }
    if(i==n) cout << "0";
    else cout << i;
    return 0;
}