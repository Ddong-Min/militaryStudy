#include<iostream>
#include<cstring>
#include<climits>

using namespace std;

int dx[6]={1,0,0,-1,0,0};
int dy[6]={0,1,0,0,-1,0};
struct Coord{
    int x;
    int y;
};

class Queue{
private:
    int rear=0;
    int front = 0;
    int size;
    Coord* q;
public:
    Queue(int M, int N){
        size=M*N;
        q=(Coord*)malloc(sizeof(Coord)*size);
    }
    ~Queue(){
        free(q);
    }
   void push(Coord data) {
        q[rear] = data;
        rear = (rear + 1) % size;
    }

    Coord pop() {
        Coord data = q[front];
        front = (front + 1) % size;
        return data;
    }

    bool empty(){
        return (front==rear ?  true : false);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M, N, H;

    cin >> M >> N;
    Queue queue(M,N);
    Coord coord;
    int tomato[N+2][M+2];
    memset(tomato , -1, sizeof(tomato));

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> tomato[i][j];
            if(tomato[i][j]==1){
                queue.push(Coord{j,i});
            }
        }
    }

    while(!queue.empty()){
        Coord parent = queue.pop();
        for(int i=0; i<6; i++){
            Coord nc;
            nc.x=parent.x+dx[i];
            nc.y=parent.y+dy[i];
            int pValue=  tomato[parent.y][parent.x];
            int newvalue = tomato[nc.y][nc.x];
            if(newvalue == 0 || newvalue > pValue+1){
                queue.push(nc);
                tomato[nc.y][nc.x] = pValue+1;
            }
        }
    }
    int max=0;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(tomato[i][j]>max) max = tomato[i][j];
            else if(tomato[i][j]==0) max=INT_MAX;
            
        }
    }
    
    if(max == INT_MAX) cout << "-1";
    else cout << max-1;
}
