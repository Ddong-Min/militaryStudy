/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void quickSort(vector<int>& arr, int start, int end){
    int i=start+1, j=end, pivot=start;
    int temp;
    if(start >= end) return;
    
    while(i<=j){
        while(arr[pivot] >= arr[i] && i<=end){
            i++;
        }
        while(arr[pivot] < arr[j] && j>start){
            j--;
        }
        if(j<i){
            temp = arr[pivot];
            arr[pivot] = arr[j];
            arr[j]=temp;
        }
        else{
            temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    quickSort(arr, start, j-1);
    quickSort(arr, j+1, end);
}

int main(){
    ios_base::sync_with_stdio(false); // 빠른 입출력
    cin.tie(NULL);

    int n;
    cin >> n;
    //vector<int> arr(n);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    //quickSort(arr,0,n-1);
    sort(arr, arr+n);
    for(int i=0; i<n; i++){
        cout << arr[i] << endl;
    }
    free(arr);
}

*/

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10000; // 입력되는 수의 최댓값

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> count(MAX + 1, 0); //max+1개의 원소 0으로초기화

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        count[num]++;
    }

    // 정렬된 출력
    for (int i = 1; i <= MAX; i++) {
        while (count[i]--) {
            cout << i << '\n';
        }
    }

    return 0;
}
