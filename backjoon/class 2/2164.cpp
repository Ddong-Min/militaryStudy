#include<iostream>

using namespace std;

template<typename T, int size>
class Queue{
public:
    T queue[size];
    int rear=0;
    int front=0;

    void push(int data){
        rear = (rear+1)%size;
        queue[rear] = data;
    }
    int pop(){
        int length = (front > rear) ? rear+size-front : rear-front;
        if(length == 1) return length;
        else{
            front = (front+1)%size;
            rear = (rear+1)%size;
            queue[rear] = queue[(front+1)%size];
            front = (front+1)%size;
            return length;
        }
    }
    void print(){
        cout << queue[rear] << '\n';
    }
};

int main(){
    int N;
    Queue<int, 500001> que;
    cin >> N;
    for(int i=1; i<=N; i++){
        que.push(i);
    }
    while(1){
        if(que.pop()==1){
            que.print();
            break;
        }
    }
}