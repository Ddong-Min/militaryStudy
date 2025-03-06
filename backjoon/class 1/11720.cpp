#include<iostream>
#include<string>

using namespace std;

int main(){
    int n, sum=0;
    string s;

    cin >> n;
    cin >> s;
    while(n--){
        sum+=(s[n]-'0');
    }
    cout << sum;
}