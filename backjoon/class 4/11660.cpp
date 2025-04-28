#include <iostream>

using namespace std;

int map[1026][1026];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
            map[i][j] += map[i-1][j];
        }
    }
    int x1, x2, y1, y2;

    while(M--){
        cin >> y1 >> x1 >> y2 >> x2;
        int ans=0;
        for(int i=x1; i<=x2; i++){
            ans += (map[y2][i]-map[y1-1][i]);
        }

        cout << ans << '\n';
    }
    
    return 0;
}