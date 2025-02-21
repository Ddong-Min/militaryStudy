#include<iostream>

using namespace std;

int main(){
    int n, order[6], T, P;
    cin >> n;
    for(int i=0; i<6; i++){
        cin >> order[i];
    }
    cin >> T >> P;

    int sum=0;
    for(int i=0; i<6; i++){
        if(!(order[i]%T)) sum+= order[i]/T;   //!(order[i]%T) 이렇게 괄호 씌우고 !해야하네
        else sum+=(order[i]-((order[i])%T))/T+1;
        //sum+=(order[i]+T-1)/T; 해도되네!?
    }
    cout << sum << endl;

    int one = n%P;
    int bundle = (n-one)/P;

    cout << bundle << " " << one;
}