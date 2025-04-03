#include <iostream>
#include<utility>
#include <cstring>
using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

class Queue{
private:
    int rear=0;
    int front=0;
    pair<int, int>* q;
public:
    Queue(int n, int m){
        q = (pair<int, int>*)malloc(sizeof(pair<int, int>*)*n*m);
    }
    ~Queue(){
        free(q);
    }

    void push(pair<int, int> coord){
        q[rear++] = coord;
    }

    pair<int,int> pop(){
        return q[front++];
    }

    bool empty(){
        return front == rear ? true : false;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    int map[n+2][m+2]={};
    int distance[n+2][m+2];
    memset(distance, -1, sizeof(distance));
    pair<int, int> target;
    Queue queue(n,m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> map[i][j];
            if(map[i][j]==2) target = make_pair(i,j);
            if(map[i][j]==0) distance[i][j]=0;
        }
    }



    queue.push(target);
    map[target.first][target.second] = 0;
    distance[target.first][target.second]=0;
    while(!queue.empty()){
        auto now = queue.pop();
        for(int i=0; i< 4; i++){
            int ty = now.first + dy[i];
            int tx = now.second + dx[i];
            if(map[ty][tx] == 1){
                queue.push(make_pair(ty, tx));
                map[ty][tx]= 0;
                distance[ty][tx] = distance[now.first][now.second]+1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << distance[i][j] << " ";
        }
        cout << endl;
    }
    
    
    
    
    return 0;
}