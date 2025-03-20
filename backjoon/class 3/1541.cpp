#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    string s;
    queue<int> q;
    int value=0, front = 0;

    cin >> s;
    
    for(int i=0; i<s.length(); i++){
        if(s[i] == '-' || s[i]=='+'){
            value += stoi(s.substr(front, i-front));
            front= i+1;
            if(s[i]=='-'){
                q.push(value);
                value=0;
            }
        }
    }
    value+=stoi(s.substr(front, s.length()-front));
    q.push(value);

    int ans=q.front();
    q.pop();
    while(!q.empty()){
        ans-=q.front();
        q.pop();
    }
    
    cout << ans;
    return 0;
}


