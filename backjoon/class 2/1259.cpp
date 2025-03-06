#include<iostream>
#include<cstring>

using namespace std;

int main(){
    char palin[6];
    int i;

    while(1){
        scanf("%s", palin);
        int len = strlen(palin);
        if(palin[0] == '0') break;
        else{
            for(i=0; i<(len+1)/2; i++){
                if(palin[i]!=palin[len-i-1]){
                    cout << "no" << endl;
                    break;
                }
            }
            if(i==(len+1)/2) cout << "yes" << endl;
        }
    }
}