#include<iostream>

using namespace std;

int main(){
    int n,max=0;
    cin >> n;
    float score[n], sum =0;
    for(int i=0; i<n; i++){
        cin >> score[i];
        if(score[max] < score[i]) max = i; //max를 float형으로 처음에 했음 배열에 인덱스는 float불가능
    }
    for(int i=0; i<n; i++){
        sum += (score[i]/score[max])*100;
    }
    /* cout에서 소수점 설정 */
    cout << fixed;
    cout.precision(5);
    cout << sum/n;
}