#include<iostream>

using namespace std;

// 1부터 시작, 안나온거 중에 가장 앞에있는 놈은 '셀프넘버', 그 셀프넘버를 생성자로 해서 다시 생성, if 앞에서 나온게 결과로 나왔다하면 해당 cycle은 종료.
// 한번도 안나온 숫자가 하나면 종료 마지막 숫자역시 셀프넘버
int main(int argc, char** argv)
{
    int num;
    int temp;
    int arr[10001]={};
    for(int i = 1; i <= 10000; i++){
        if(arr[i] == 0){
        cout << i << endl;
        num = i;
        for(;num<=10000;){
            if(arr[num] == 1) break;
            arr[num] = 1;
            temp = num;
            for(;temp > 0;temp/=10){
                num += temp%10;
            }
            }
        }
    }
    return 0;
}
