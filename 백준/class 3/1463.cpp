#include<iostream>
#include <algorithm>
using namespace std;

int cal[1000001] = {0,0,1,1};

int Topdown(int n){
    if(n==1) return 0;
    if(cal[n] != 0) return cal[n];
    if(n%6==0){
        cal[n] = min({Topdown(n/3), Topdown(n/2), Topdown(n-1)})+1;
    }

    else if(n%3==0){
        cal[n] = min({Topdown(n/3), Topdown(n-1)})+1;
    }

    else if(n%2==0){
        cal[n] = min({Topdown(n/2), Topdown(n-1)})+1;
    }
    else {
        cal[n] = Topdown(n-1)+1;
    }
    return cal[n];

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << Topdown(n);
}

//아래는 바보풀이
/*
#include<iostream>
#include <algorithm>
using namespace std;

int cal[100001] = {};

int Topdown(int n){
    if(n==1) return 0;
    if(n%6==0){
        if(cal[n/3] == 0) cal[n/3]=Topdown(n/3);
        if(cal[n/2] == 0) cal[n/2]=Topdown(n/2);
        if(cal[n-1] == 0) cal[n-1]=Topdown(n-1);
        return min({cal[n/3], cal[n/2], cal[n-1]})+1;
    }

    else if(n%3==0){
        if(cal[n/3] == 0) cal[n/3]=Topdown(n/3);
        if(cal[n-1] == 0) cal[n-1]=Topdown(n-1);
        return min(cal[n/3], cal[n-1])+1;
    }

    else if(n%2==0){
        if(cal[n/2] == 0) cal[n/2]=Topdown(n/2);
        if(cal[n-1] == 0) cal[n-1]=Topdown(n-1);
        return min(cal[n/2], cal[n-1])+1;
    }
    else {
        if(cal[n-1] == 0) cal[n-1]=Topdown(n-1);
        return cal[n-1]+1;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << Topdown(n);
}*/