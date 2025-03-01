#include<iostream>

using namespace std;

class Queue{
private:
    int front;
    int rear;
    int size;
    int* queue;
public:
    Queue(int f, int r, int s) : front(f), rear(r), size(s){
        queue = (int*)malloc(sizeof(int)*size);
    }
    ~Queue(){ free(queue);}
    void push(int data){
        rear = (rear+1)%size;
        queue[rear] = data;
    }
    int pop(int jump){
        for(int i=1; i<=jump;i++){
            front = (front+1)%size;
            if(i==jump) {
                size--;
                return queue[front];
            }
            else{
                rear=(rear+1)%size;
                queue[rear]=queue[front];
            }
        }
    }
    int empty(){
        return front > rear ? rear+size-front : front-rear;
    }
};

int main(){
    int n,k, yose;
    Queue que(0,0,n);
    cin >> n >> k;

    for(int i=1; i<=n; i++){
        que.push(i);
    }
    cout << "<";
    while(1){
        cout << que.pop(k);
        if(que.empty()!=0) {
            cout << ", ";
        }
        else break;
    }
    cout << ">";
}