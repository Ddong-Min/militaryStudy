#include<iostream>

using namespace std;

int main(){
    int n, sum=1, i,m, room=1;;
    cin >> n;
    for(i=1; sum < n; i++){
        sum+=6*i;
        room+=1;
    }
    cout << room;
}

//1 -> 6 -> 12 -> 18
/*
6 18 36 60
 12 18 24
1 1+6 1+6+12 
1  2    3 
*/