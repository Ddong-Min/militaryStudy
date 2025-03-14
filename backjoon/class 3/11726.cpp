#include <iostream>

using namespace std;

int square[1001]={0, 1, 2}; //사각형안에 타일을 넣을 수 있는 가지수를 담는 배열

//2*n 타일 채우는 가지수 = 2*(n-1) 채우는 가지수 + 2*(n-2)채우는 가지수
int Topdown(int target){
    if(square[target]!=0) return square[target];
    
    //n이 402만 되어도 타일 채우는 가지수가 int의 범위를 넘어섬
    //overflow오류를 피하기 위해서 square배열에 넣을때마다 10007의 나머지를 계산해서 넣어줌
    square[target] = (Topdown(target-1)+Topdown(target-2))%10007;
    return square[target];
}
int main() {
    int n;

    cin >> n;
   	cout << Topdown(n);

    return 0;
}