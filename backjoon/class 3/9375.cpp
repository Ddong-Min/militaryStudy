#include<iostream>
#include<map>
#include<string>
#include<set>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, n, ans;
    string name, type;
    cin >> T;
    
    while(T--){
        ans=1; //1로 초기화
        //key가 중복될 수 있으므로 multimap을 활용해서 하나의 key에 여러 value가
        //들어갈 수 있도록 함
        multimap<string, string> col;

        //key값이 중복없이 몇개있는지, 어떤것이 있는지 확인하기 위해 set사용
        set<string> s;
        
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> name >> type;
            col.insert(pair<string, string>(type, name));
            s.insert(type);
        }
        
        for(auto iter = s.begin(); iter!= s.end(); iter++){
            //만약 하나의 key에 2개의 value가 있으면 여기서 나올 수 있는 경우가
            //하나도 선택 안한경우, value1선택한 경우, value2선택한 경우로 3개이므로 +1해줌
            ans *= col.count(*iter)+1;
        }
        ans = ans - 1; //아무것도 선택하지 않은 경우(알몸)을 제외하기 위해 -1해줌
        cout << ans << '\n';
    }
}