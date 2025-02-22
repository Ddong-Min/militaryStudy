#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    long long hash=0, weight=1;
    string s;
    cin >>n;
    cin >> s;
    for(int i=0; i<n; i++){
        hash = (hash+((s[i]-'a'+1)*weight)) % 1234567891;
        weight = (weight*31)%1234567891;
    }
    cout << hash;
}

/*
weight = (weight)%1234567891;
hash += ((s[i]-'a'+1)*weight) % 1234567891;
hash %= 1234567891;
weight *=31;
원래는 이걸로 했는데 큰 값이 들어오면 오류

이유는 4번째줄에서 잘못하면 int범위 넘어섬
그리고 2번째줄도 잘못하면 이미 hash에 큰값있고 우연히 큰값들어올때 int범위 넘어설수있음

따라서 정답처럼 해야함
*/