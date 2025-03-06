#include<iostream>

using namespace std;

int main(){
    int n, k, child=1, mother=1;

    cin >> n >> k;

    for(int i=1; i<=k; i++){
        child*=n+1-i;
        mother*=i;
    }

    cout << child/mother;
}