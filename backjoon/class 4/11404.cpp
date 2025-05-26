#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, u, v, w;
    long long map[102][102];
    long long INF = 100000*100000+1;
    cin >> n;
    cin >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i!=j) map[i][j]=INF;
            else map[i][j]=0;
        }
    }
    while(m--){
        cin >> u >> v >> w;
        if(map[u][v] > w) map[u][v]=w;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(map[i][j] > (map[i][k]+map[k][j])) map[i][j] = (map[i][k]+map[k][j]);
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(map[i][j] == INF) cout << 0 << " ";
            else cout << map[i][j] << " ";
        }
        cout << endl;
    }
}