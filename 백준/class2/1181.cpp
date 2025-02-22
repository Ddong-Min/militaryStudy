#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void quickSort(int* arr, int start, int end){
    int pivot = start;
    int i = start+1, j=end;
    if(start>=end) return;
    while(i<=j){ //바보같이 i>j로 했었음 다시 말하지만 while문 조건은 안에 들어갈 조건이다
        while(arr[pivot] > arr[i] && i<=end){
            i++;
        }
        while(arr[pivot] <= arr[j] && j>start){
            j--;
        }
        if(i > j){
            int temp = arr[pivot];
            arr[pivot] = arr[j];
            arr[j] = temp;
        }
        else{
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    quickSort(arr, start, j-1);
    quickSort(arr, j+1, end);
}

int main(){
    int n;
    cin >> n;
    string s;
    int arr[n]={}, weight=1;
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=s.length()-1; j>=0;j--){
            if(j!=s.length()-1) weight*=10;
            arr[i]+=(s[j]-'a'+1)*weight;
        }
    }
    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        string result = "";
        while (arr[i] > 0) {
            result += (arr[i] % 10) + 'a' - 1;
            arr[i] /= 10;
        }
        reverse(result.begin(), result.end()); // reverse로 다시 순서를 바꿈
        cout << result << endl;
    }
        /*
        char c[50];
        int j=0;
        for(;arr[i]>0;arr[i]/=10){
            c[j]=(arr[i]%10+'a'-1);
            j++;
        }
        s=c;
        reverse(s.begin(),s.end());
        cout << s << endl;
    }
        */

}