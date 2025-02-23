#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int arr[N];
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    quickSort(arr, 0, N-1);
    //sort(arr, arr+N);
    for(int i=0; i<N; i++){
        cout << arr[i] << '\n'; //endl로 하면 틀리고 '/n'은 맞음
    }

}

/*
void quickSort(int* arr, int start, int end){
    if(start >=end) return;
    int i=start+1, j=end, pivot = start;
    while(i<=j){
        while(arr[pivot] > arr[i] && i<=end) i++;
        while(arr[pivot] < arr[j] && j>start) j--;
    }

    if(i>j){
        int temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
    }
    else{
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    quickSort(arr, start, j-1);
    quickSort(arr, j+1, end);
}