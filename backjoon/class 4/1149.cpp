#include <iostream>
#include <climits>
using namespace std;

int rgb[1000][3];
int N;
int memo[1000][3];
int topDown(int row, int prev){
    int temp;
    int sum = INT_MAX;
    if(row==N){
        return 0;
    }
    if(memo[row-1][prev]) return memo[row-1][prev];
    for(int i=0; i<3; i++){
        if(prev!=i){
            temp = rgb[row][i] + topDown(row+1, i);
            if(sum > temp) sum = temp;
        }
    }
    if(row) memo[row-1][prev] = sum;
    return sum;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin >> rgb[i][j];
        }
    }
    cout << topDown(0, -1);
    
    return 0;
}