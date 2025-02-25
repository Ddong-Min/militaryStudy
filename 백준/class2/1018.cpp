#include<iostream>

using namespace std;

char white[8][8], black[8][8];

int makeChess(char chess[50][50], int v, int h){
    int Wcount=0, Bcount=0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(white[i][j] != chess[i+v][j+h]) Wcount++;
            if(black[i][j] != chess[i+v][j+h]) Bcount++;
        }
    }
    return Wcount < Bcount ? Wcount : Bcount;
}

int main(){
    int n,m, min=2500, ans;
    char chess[50][50];
    cin >> n >> m;

    for(int i=0; i<8;i++){
        for(int j=0; j<8; j++){
            if((i+j)%2==0){
                white[i][j]='W';
                black[i][j]='B';
            }
            else{
                white[i][j]='B';
                black[i][j]='W';
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> chess[i][j];
        }
    }
    for(int i=0; i<=n-8; i++){
        for(int j=0; j<=m-8; j++){
            ans=makeChess(chess, i, j);
            if(min > ans) min = ans;
        }
    }
    cout << min;

}