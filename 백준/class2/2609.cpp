#include<iostream>

using namespace std;

int uclid(int a, int b){
    if(b==0) return a;
    return uclid(b, a%b);
}

int main(){
    int a, b, min;
    cin >> a>>b; //이걸 입력 받지 않아서.. 틀린거
    min = uclid(a,b);
    cout << min << endl;
    cout << (a/min)*b << endl;
}

//min이 0이 되었어서 sigfpe오류가 발생했었음. 
//sigfpe는 분모가 0이되서 주로 발생하는 오류

/*왜 발생했나 했더니 바보같이ㅏ a, b를 입력받지 않음*/