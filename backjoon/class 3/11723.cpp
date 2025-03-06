/*
#include<iostream>
#include<string>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool set[21]={};
    int n, data;   
    string cmd;
    cin >> n;
    while(n--){
        cin >> cmd;
        if(cmd.compare("add") == 0){
            cin >> data;
            set[data]=1;
        }
        else if(cmd.compare("remove")==0){
            cin >> data;
            set[data]=0;
        }
        else if(cmd.compare("check")==0){
            cin >> data;
            cout << set[data] << '\n';
        }
        else if(cmd.compare("toggle")==0){
            cin>>data;
            set[data]=set[data]^1;
        }
        else if(cmd.compare("all")==0){
            for(int i=1; i<=20; i++){
                set[i]=1;
            }
        }
        else if(cmd.compare("empty")==0){
            for(int i=1; i<=20; i++){
                set[i]=0;
            }
        }
    }
}
*/
#include<iostream>
#include<string>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, data, s=0;
    string cmd;
    cin>> n;
    while(n--){
        cin >> cmd;
        if(cmd.compare("add")==0){
            cin >> data;
            s |= 1<<data;
        }
        else if(cmd.compare("remove")==0){
            cin >> data;
            s &= ~(1<<data);
        }
        else if(cmd.compare("check")==0){
            cin >> data;
            if(s & 1<<data) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(cmd.compare("toggle")==0){
            cin >> data;
            if(s& 1<<data) s&=~(1<<data);
            else s|=(1<<data);
        }
        else if(cmd.compare("all")==0){
            s = (1<<21)-1; //1<<21-1로 하면 사칙연산이 우선순위가 높아서 틀림
        }
        else if(cmd.compare("empty")==0){
            s=0;
        }
    }
}