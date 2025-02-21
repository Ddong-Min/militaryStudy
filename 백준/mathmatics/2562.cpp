#include<iostream>

using namespace std;

int main(){
    int i, arr[9], max=0;
    for(i=0; i<9; i++){
        scanf("%d", &arr[i]);
        if(arr[i]>arr[max]) max=i;
    }
    printf("%d\n", arr[max]);
    printf("%d", max+1);
}