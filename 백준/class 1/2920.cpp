#include<iostream>
#include<string>
using namespace std;

int main(){
    int arr[8], i;
    string s;
    for(i=0; i<8; i++){
        cin >> arr[i];
    }
    for(i=0; i<7; i++){
        if(arr[i]+1 != arr[i+1]) break;
    }
    if(i==7) s="ascending";
    for(i=0; i<7; i++){
        if(arr[i]-1 != arr[i+1]) break;
    }
    if(i==7) s="descending";

    if(s=="\0") s="mixed";

    cout << s;
}