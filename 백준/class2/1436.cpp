#include<iostream>
#include<string>

using namespace std;

int main(){
    int n, i=665,count =0;
    string s;
    cin >> n;

    while(count < n){
        i++;
        s=to_string(i);
        int found = s.find("666");
        if(found != string::npos){
            count++;
        }
    }
    cout << i;
}

