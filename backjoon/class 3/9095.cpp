#include <iostream>

using namespace std;

int exp[12];

/*정수 n일때 1,2,3의 합으로 나타낼 수 있는개수
    exp[n] = exp[n-1]+exp[n-2]+exp[n-3]
*/
int Topdown(int n){
    if(exp[n] != 0) return exp[n];
    exp[n]=Topdown(n-1)+Topdown(n-2)+Topdown(n-3);
    return exp[n];
}

int main() {
    int T, n; // T: 테스트 케이스 수, n : 각 테스트 케이스 target 정수
    cin >> T;
    exp[1]=1;
    exp[2]=2;
    exp[3]=4;
    for(int i=0; i<T; i++){
        cin >> n;
        cout << Topdown(n) << endl;
    }
    return 0;
}