#include<iostream>

using namespace std;

int main(){
    int a,b,c,mul=1;
    int arr[10]={};
    cin >> a >> b >> c;
    mul=a*b*c;
    for(;mul>0; mul/=10){
        arr[mul%10]++;
    }
    for(int i=0; i<10; i++){
        cout << arr[i] << endl;
    }
}