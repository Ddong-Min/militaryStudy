#include<iostream>
#include<algorithm>
using namespace std;

/*
void selectSort(int* A, int n){
    int min_index;
    for(int i=0; i<n-1; i++){
        min_index = i;
        for(int j=i; j<n; j++){
            if(A[min_index] > A[j]) min_index = j;
        }
        if(min_index != i){
            int temp = A[i];
            A[i]=A[min_index];
            A[min_index]=temp;
        }
    }
}*/
void quickSort(int* A, int left, int right){
    if(left >= right){
        return;
    }
    int pivot = left;
    int i = left+1, j= right;

    while(i <= j){ //이걸 ㅄ같이 i>=j로 함 이럼 while문에 들어갈수조차 없잖아
        while(A[pivot] >= A[i] && i<=right) {i++;} //얘도 A[pivot] <= A[i]로 함 
        while(A[pivot] <= A[j] && j >left) {j--;}
        if(i < j){
            int temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
        else if(i>j){
            int temp = A[j];
            A[j] = A[pivot];
            A[pivot] = temp;
        }
    }

    quickSort(A, left, j-1);
    quickSort(A, j+1, right);
}
void binarySearch(int* A, int left, int right, int data){
    int mid = (left+right)/2;
    if(left > right) printf("0\n");
    else if(A[mid]==data) printf("1\n");
    else if(left == right) printf("0\n");
    else if(A[mid] > data) binarySearch(A, left, mid-1, data);
    else if(A[mid] < data) binarySearch(A, mid+1, right, data);
}

int main(int argc, char** argv)
{
    int n, m;
    scanf("%d", &n);
    int A[n];
    int i=n, data;
    while(i--){
        scanf("%d", &A[n-i-1]); //i가 바로 n-1로 1감소하고 들어오네
    }
    //quickSort(A, 0, n-1);
    sort(A, A+n);
    scanf("%d", &m);
    while(m--){
        scanf("%d", &data);
        binarySearch(A, 0,n-1,data);
    }
    return 0;
}


/* cin, cout보다 scanf printf가 더빠름
quick sort보다 stl sort함수가 더빠른데 이유는 내일 알아보자 */