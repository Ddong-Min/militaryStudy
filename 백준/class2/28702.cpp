#include<iostream>
#include<string.h>
using namespace std;

int main(){
    int i=0, weight = 1, sum=0;
    string s;
    while(i<3){
        cin >> s;
        if(s!="Fizz" && s!="Buzz" && s!="FizzBuzz"){ //c++에서 string자체로 비교는 위아래 둘다 가능
        //if(s.compare("Fizz") !=0 && s.compare("Buzz")!=0 && s.compare("FizzBuzz")!=0){
            for(int j=s.length()-1; j>=0; j--){
                if(j!=s.length()-1) weight*=10;
                sum+=(s[j]-'0')*weight;
            }
            sum+=(3-i);
            break;
        }
        i++;
    }
    if(sum%15==0) cout << "FizzBuzz";
    else if(sum%5==0) cout << "Buzz";
    else if(sum%3==0) cout << "Fizz"; 
    else cout << sum;
}

