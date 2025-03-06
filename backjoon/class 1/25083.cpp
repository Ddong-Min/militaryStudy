#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    s="         ,r'\"7\n";
    s+="r`-_   ,'  ,/\n";
    s+=" \\. \". L_r'\n";
    s+="   `~\\/\n";
    s+="      |\n";
    s+="      |";
    printf("%s", s.c_str());
}

/* 문자열에서 \출력하려면 \\이렇게 젂
"출력도 \"이렇게 */