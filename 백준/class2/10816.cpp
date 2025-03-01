/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void quickSort(vector<int>& arr, int start, int end){
    int pivot = start;
    int i=start+1, j=end;
    if(start>=end) return;

    while(i<=j){
        while(i<=end && arr[pivot] >= arr[i]){ //arr[pivot] > arr[i]로 처음에 했는데
            //이경우에는 같은 값이 들어오면 무한루프에 빠질수도 있음
            //ex pivot의 값이 7이고 i,j둘다 10이면 둘다 계속 서로 바꿈
            i++;
        }
        while(j>start && arr[pivot] <= arr[j]){
            j--;
        }
        if(i>j){
            int temp = arr[pivot];
            arr[pivot]=arr[j];
            arr[j]=temp;
        }
        else{
            int temp = arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    quickSort(arr,start,j-1);
    quickSort(arr,j+1,end);
}

int lowerbound(vector<int>& arr, int start, int end, int data){
    while(start<=end){
        int mid = (start+end)/2;
        if(data > arr[mid]) start = mid+1;
        else end = mid-1;
    }
    return start;
}

int upperbound(vector<int>& arr, int start, int end, int data){
    while(start<=end){
        int mid = (start+end)/2;
        if(data >= arr[mid]) start = mid+1;
        else end = mid-1;
    }
    return start;
}

int main(){
    //이걸 쓰니까 합격함
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, ans;
    cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    quickSort(arr,0,N-1);
    //sort(arr.begin(), arr.end());
    cin >> M;

    for(int i=0; i<M; i++){
        int count=0;
        cin >> ans;
        cout << upperbound(arr,0,N-1,ans)-lowerbound(arr,0,N-1,ans) << " ";
        //cout << upper_bound(arr.begin(), arr.end(), ans) - lower_bound(arr.begin(), arr.end(), ans) << " ";
    }
    
} */

#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, int> m;
    int N, M, n;
    cin >> N;

    while(N--){
        cin >> n;
        m[n]++; 
    }
    cin >> M;
    while(M--){
        cin >> n;
        auto it = m.find(n);

        if(it != m.end()) cout << it->second << " ";
        else cout << "0" << " ";
    }
}
