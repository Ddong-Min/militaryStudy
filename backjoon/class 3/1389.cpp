#include<iostream>
#include<climits>
using namespace std;

int main(){
    int N, M, v, e;

    cin >> N >> M;

    int kb[N+1][N+1]={};

    while(M--){
        cin >> v >> e;
        kb[v][e]=1;
        kb[e][v]=1;
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i!=j && kb[i][j]==0){
                kb[i][j]=100;
            }
        }
    }
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                kb[i][j]=min(kb[i][j], kb[i][k]+kb[k][j]);
            }
        }
    }

    int minn=INT_MAX;
    int min_index;
    for(int k=1; k<=N; k++){
        int sum=0;
        for(int i=1; i<=N; i++){
            sum+=kb[k][i];
        }
        if(minn > sum){
            minn = sum;
            min_index=k;
        }
    }
    cout << min_index;
}