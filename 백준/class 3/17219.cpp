#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
    int n, m;
    string address, password;
    map<string, string> memo;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> address >> password;
        memo.insert({address, password});
    }
    for(int i=0; i<m; i++){
        cin >> address;
        cout << memo.find(address)->second << '\n';
    }
}