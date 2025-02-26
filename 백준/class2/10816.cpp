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

int binarySearch(vector<int>& arr, int start, int end, int data){
    int mid = (start+end)/2;
    if(data == arr[mid]) return mid;
    else if(start >= end) return -1;
    else if(data > arr[mid]) return binarySearch(arr,mid+1,end,data);
    else if(data < arr[mid]) return binarySearch(arr, start, mid-1,data);
}
int main(){
    int N, M, ans;
    cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    //quickSort(arr,0,N-1);
    sort(arr.begin(), arr.end());
    cin >> M;

    for(int i=0; i<M; i++){
        int count=0;
        cin >> ans;
        int point = binarySearch(arr,0,N-1,ans);
        if(point != -1){
            int tpoint = point;
            while(tpoint >= 0 && arr[tpoint--]== ans){
                count++;
            }
            while(point < N-1 && arr[++point]==ans){
                count++;
            }
        }
        cout << count << " ";
    }
    
}