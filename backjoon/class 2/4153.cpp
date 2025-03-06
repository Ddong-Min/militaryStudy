#include<iostream>
using namespace std;
int main(){
    int a[3];

    while(true){
        cin >> a[0] >> a[1] >> a[2];
        int sum1=0, sum2=0;
        if(a[0]==0 && a[1]==0 && a[2]==0) break;
        if(a[0]==0||a[1]==0||a[2]==0) cout << "wrong"<<endl;
        else{
            int max = 0;
            if(a[max] < a[1]) max = 1;
            if(a[max] < a[2]) max = 2;
            for(int i=0; i<3; i++){
                if(max == i) sum1 += a[i]*a[i];
                else sum2 += a[i]*a[i];
            }
        }
        if(sum1 == sum2) cout << "right" << endl;
        else cout << "wrong" << endl;
    }
}