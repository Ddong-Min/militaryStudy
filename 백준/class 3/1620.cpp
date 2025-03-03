#include<iostream>
#include<map>
#include<string>

using namespace std;

string pok[100001];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    string s;
    cin >> n >> m;
    map<string, int> dic;

    for(int i=1; i<=n; i++){
        cin >> s;
        dic.insert({s,i});
        pok[i]=s;
    }

    for(int i=0; i<m; i++){
        cin >> s; 
        if(s[0] >='1' && s[0] <= '9'){
            cout << pok[stoi(s)] << '\n';
        }
        else{
            cout << dic.find(s)->second << '\n';
        }
    }
}