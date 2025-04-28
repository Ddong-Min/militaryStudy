#include <iostream>
#include <cstring>
using namespace std;

int* sti[2];
int* sum[2];
int n;
int Topdown(int y, int x){
    if(x < 0 || x >= n) return 0;
    if(sum[y][x]!=-1) return sum[y][x];
    int dy = (y==1 ? 0 : 1);
    sum[y][x]=max(Topdown(dy, x+1), Topdown(dy, x+2))+sti[y][x];
    return sum[y][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;

    while(T--){
        int maxVal = 0;
        cin >> n;
        for (int i = 0; i < 2; i++) {
            sti[i] = (int*)malloc(sizeof(int) * n);
            sum[i] = (int*)malloc(sizeof(int) * n);
        }

        for (int i = 0; i < 2; i++) {
            memset(sum[i], -1, sizeof(int) * n); // sum[i]에 대해 각각 초기화
        }
        
        for(int i=0; i<2; i++){
            for(int j=0; j<n; j++){
                cin >> sti[i][j];
            }
        }
        for(int i=0; i<2; i++){
            int temp = Topdown(i, 0);   
            maxVal = max(temp, maxVal);
        }        
        
        cout << maxVal << '\n';
    }
    return 0;
}