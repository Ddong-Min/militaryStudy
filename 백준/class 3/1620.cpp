#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    string s;
    cin >> n >> m;
    map<int,string> dic;
    for(int i=1; i<=n; i++){
        cin >> s;
        dic.insert({i,s});
    }
    for(int i=0; i<m; i++){
        cin >> s; 
        if(s[0] >='1' && s[0] <= '9'){
            int key = stoi(s);
            cout << dic.at(key) << '\n';
        }
        /*value값으로 key값 찾기*/
        else{
            int temp;
            for(auto itr=dic.begin(); itr!=dic.end(); itr++){
                if(itr->second == s){
                    temp = itr->first;
                }
            }
            cout << temp << '\n';
        }
    }

}