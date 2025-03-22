#include <iostream>

using namespace std;

int** square, blue = 0, white = 0;

void Topdown(int row, int column, int N){
    int weight=0;
    int dx[4]={0,N/2,0,N/2};
    int dy[4]={0,0,N/2,N/2};
    for(int i=row; i<row+N; i++){
        for(int j=column; j<column+N; j++){
            weight += square[i][j];
        }
    }
    if(weight == N*N) blue ++;
    else if(weight == 0) white++;
    else{
        for(int i=0; i<4; i++){
            Topdown(row+dx[i], column+dy[i], N/2);
        }
    }
}

int main() {
    int N;
    cin >> N;

    square = (int**)malloc(sizeof(int*)*N);
    for(int i=0; i<N; i++){
        square[i] = (int*)malloc(sizeof(int)*N);
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> square[i][j];
        }
    }
    Topdown(0,0,N);

    cout << white << '\n';
    cout << blue << '\n';
    return 0;
}