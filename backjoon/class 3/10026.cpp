#include <iostream>
#include <cstring>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
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
    Queue(int N){
        size=N*N;
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
        return (front==rear ? true : false);
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, normal=0, daltonism =0;
    cin >> N;
    Queue queue(N);
    Coord coord;
    int normalPic[N+2][N+2];
    int daltoPic[N+2][N+2];
    memset(normalPic , 0, sizeof(normalPic));
    memset(daltoPic , 0, sizeof(daltoPic));
    char color;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> color;
            switch (color) {
                case 'R':
                    normalPic[i][j]=1;
                    daltoPic[i][j]=1;
                    break;
                case 'G':
                    normalPic[i][j]=2;
                    daltoPic[i][j]=1;
                    break;
                case 'B':
                    normalPic[i][j]=3;
                    daltoPic[i][j]=3;
                    break;
            };
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(normalPic[i][j] != 0){
                coord.y=i;
                coord.x=j;
                queue.push(coord);
                int Icolor = normalPic[i][j];
                normalPic[i][j]=0;
                normal++;
                while(!queue.empty()){
                    Coord parent = queue.pop();
                        for(int i=0; i<4; i++){
                            Coord child;
                            child.x = parent.x+dx[i];
                            child.y = parent.y+dy[i];
                            if(normalPic[child.y][child.x]==Icolor){
                                queue.push(child);
                                normalPic[child.y][child.x] = 0;
                            }
                        }
                    }
                }
            }
        }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(daltoPic[i][j] != 0){
                coord.y=i;
                coord.x=j;
                queue.push(coord);
                int Icolor = daltoPic[i][j];
                daltoPic[i][j]=0;
                daltonism++;
                while(!queue.empty()){
                    Coord parent = queue.pop();
                    for(int i=0; i<4; i++){
                        Coord child;
                        child.x = parent.x+dx[i];
                        child.y = parent.y+dy[i];
                        if(daltoPic[child.y][child.x]==Icolor){
                            queue.push(child);
                            daltoPic[child.y][child.x] = 0;
                        }
                    }
                }
            }
        }
    }


    cout << normal << " " << daltonism;
    return 0;
}