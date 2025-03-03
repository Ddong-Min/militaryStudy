#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int n, sum=0, max=0, max_val=0, max_val2=-4001;
    cin >> n;
    int* arr = (int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    sort(arr, arr+n);
    if(round((double)sum/n) == -0) cout << "0" << '\n';
    else cout << round((double)sum/n) << '\n';
    cout << arr[n/2] << '\n';
    
    for(int i=0; i<n; ){
        int key = arr[i];
        int upper = upper_bound(arr, arr+n, key)-arr;
        int lower = lower_bound(arr, arr+n, key)-arr;
        i=upper;
        if(max < upper-lower) {
            max = upper-lower;
            max_val = arr[lower];
            max_val2=-4001;
        }
        else if(max == upper-lower && max_val2==-4001){
            max_val2 = arr[lower];
        }
    }
    if(max_val2!=-4001) cout << max_val2 << '\n';
    else cout << max_val << '\n';
    cout << arr[n-1]-arr[0];
}