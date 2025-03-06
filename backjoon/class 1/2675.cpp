#include<iostream>
#include<string>

using namespace std;

int main(){
    int n, r;
    string s;
    scanf("%d", &n);

    while(n--){
        // scanf("%d %s",&r, s); string은 scanf로 못받음

        cin >> r >> s;
        
        int len = s.length();
        for(int i=0; i<len; i++){
            for(int j=0; j<r; j++){
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }

}