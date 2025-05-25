#include<iostream>

using namespace std;

int seq[1001];
int DP[1001][2];
int N;
int Topdown(int n, int isIncrease){
    if(DP[n][isIncrease]) return DP[n][isIncrease];
    for(int i=n-1; i >=0; i--){
        int temp;
        if(seq[i] < seq[n]){
            temp = Topdown(i, 1)+1;
            if(temp > DP[n][isIncrease]) DP[n][isIncrease]=temp;
        }
        else if(isIncrease == 0 && seq[i] > seq[n]){
            temp = Topdown(i,0)+1;
            if(temp > DP[n][isIncrease]) DP[n][isIncrease]=temp;
        }
    }
    return DP[n][isIncrease];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> seq[i];
    }
    cout << Topdown(N, 0);

}