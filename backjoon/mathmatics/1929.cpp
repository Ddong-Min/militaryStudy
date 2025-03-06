#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;


//using sqrt version => but this version is timeout
/*
int main(int argc, char** argv)
{
    int m,n, i;
    cin >> m >> n;
    for(;m<=n; m++){
        for(i=2; i<=int(sqrt(m)); i++){
            if(m%i == 0) break;
        }
        if(i == int(sqrt(m))+1){
            cout << m << endl;
        }
    }
    return 0;
}s
*/

//using 에라토스테네스의 체
//why erathostemes is faster than sqrt?
int main(int argc, char** argv){
    int_least16_t arr[1000001]={};
    int m, n;

    cin >> m >> n;
    arr[1] = 1;
    
    for(int i=2; i*i<=n;i++){   // 1. 에라토스테네스의 체를 활용할때도 마지막 숫자(ex. 1000000도 sqrt(1000000) 안에 약수가 없었으면 소수인거 따라서 i*i<=n일때까지만 해도 괜찮 ( 20ms -> 12ms)
        if(arr[i] == 0){
            for(int j = 2*i; j<=n; j+=i){
                arr[j] = 1;
            }
        }    
    }
    for(;m<=n; m++){
        if(arr[m] == 0) printf("%d\n", m); // 2. cout으로 출력했을때 1800ms => printf()로 출력시 20ms
    }
}


//참고 :https://www.acmicpc.net/source/89070978