#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    map<string,int> noHear;
    map<string,int> noHearSee;
    int n,m, cnt=0;
    string s;

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> s;
        noHear.insert({s,i});
    }
    for(int i=1; i<=m; i++){
        cin >> s;
        if(noHear.find(s) != noHear.end()) noHearSee.insert({s,++cnt});
    }
    cout << cnt <<'\n';
    for(auto itr = noHearSee.begin(); itr!=noHearSee.end(); itr++){
        cout << itr->first << '\n';
    }
}