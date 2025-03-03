#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int n,sum=0;
    cin >> n;
    if(n!=0){
        int* arr = (int*)malloc(sizeof(int)*(n));

        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr, arr+n);
        int del = round((float)n*0.15);
        for(int i=del; i<n-del; i++){
            sum+=arr[i];
        }
        cout << round((float)sum/(n-del*2));
        free(arr);
    }
    else cout << 0;
}