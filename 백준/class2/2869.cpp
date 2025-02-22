#include <iostream>
using namespace std;

int main() {
    int a, b, v;
    cin >> a >> b >> v;

    int days = (v - b - 1) / (a - b) + 1;  //-1과 +1은 올림효과를 위한것
    //tc2처럼 v-b/a-b가 딱 떨어지지 않는다면 마지막날을 고려하지 못하게 되는 문제발생
    //실제로 2일 걸리지만 v-b/a-b로 하면 1일 걸리게 됨 따라서 +1을 해줌
    //근데 이러면 나누어떨어지는 경우는 1일이 더 나오게됨 => 그래서 v-b에서 -1을 해준것

    cout << days << endl;
    return 0;
}

//