#include<iostream>
#include<algorithm>
using namespace std;
struct Dungchi{
    int h;
    int w;
    int rank=1;
}D[51];

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> D[i].h >> D[i].w;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(D[i].h < D[j].h && D[i].w < D[j].w) D[i].rank++;
            
        }
    }
    for(int i=0; i<n; i++){
        cout << D[i].rank << " ";
    }
}