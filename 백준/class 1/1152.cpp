#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    int i,count=0;
    getline(cin, s);
    for(i=0; i<s.length(); i++){
        if(s[i]==' '){
            if(i!=0 && s[i-1] != ' ') {
                count++;
            }
        }
    }
    if(s[i-1] != ' ') count++;
    cout << count;

}

/*
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int ans;
char s[1000000];
char * ptr;
int main () 
{
	cin.getline(s, 1000000);
	ptr = strtok(s, " ");
	while (ptr!=NULL) { //끝까지 가면 NULL반환
		ans++;
		ptr = strtok(NULL, " "); //다음 문자열부터 검색
	}
	cout << ans << endl;
    return 0;
}
     */