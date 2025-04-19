#include <iostream>

using namespace std;

int arr[1000];
int arr2[1000];
int N;
int Topdown(int n){
    if(n==1) return 1;
    if(arr2[n-1]) return arr2[n-1];
    int max =1;
    int now = arr[n-1];
    for(int i=n-2; i>=0; i--){
        int temp = Topdown(i+1);
        if(now > arr[i]){
            temp++;
            if(max < temp) max = temp;
        }
        if(n==N && max < temp) max = temp;
    }
    arr2[n-1]=max;
    return max;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    cout << Topdown(N);
}