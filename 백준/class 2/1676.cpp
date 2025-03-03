#include<iostream>

using namespace std;

/*
int main(){
    int n5=0, n2=0;
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        int temp=i;
        while(1){
            if(temp%2==0){
                n2++;
                temp/=2;
            }
            else if(temp%5==0){
                n5++;
                temp/=5;
            }
            else break;
            
        }
    }
    cout << (n2 >= n5 ? n5 : n2);
}
*/

//근데 생각해보면 2의 배수가 무조건 5의배수보다 많음 그리고 500까지로 제한되있음

int main(){
    int n;
    cin>>n;
    printf("%d", n/5+n/25+n/125); //25는 5가2개니까 n/5로만 하면 안되고 n/25도 한번해주기
}