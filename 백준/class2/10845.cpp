#include<iostream>
#include<cstring>

using namespace std;

class Queue{
private:
    int rear;   
    int front;
    int size=10000;
    int queue[10001];
public:
    Queue(int f, int r):front(f), rear(r){}
    void push(int data){
        rear=(rear+1)%size;
        queue[rear] = data;
    }
    void pop(){
        if(empty() == 1) cout << "-1" << '\n';
        else{
            front = (front+1)%size;
            cout << queue[front] << '\n';
        }
    }
    int Size(){
        return front > rear ? rear+size-front : rear-front;
    }
    int empty(){
        int len = front > rear ? rear+size-front : rear-front;
        if(len == 0) return 1;
        else return 0;
    }
    int Front(){
        if(empty()==1) return -1;
        else return queue[front+1];
    }
    int Back(){
        if(empty()==1) return -1;
        else return queue[rear];
    }
};

int main(){
    int n, data;
    Queue que(0,0);
    string cmd;
    cin >> n;

    while(n--){
        cin >> cmd;
        if(cmd.compare("push")==0){
            cin >> data;
            que.push(data);
        }
        else if(cmd.compare("pop")==0){
            que.pop();
        }
        else if(cmd.compare("empty")==0){
            cout << que.empty() << '\n';
        }
        else if(cmd.compare("size")==0){
            cout << que.Size() << '\n';
        }
        else if(cmd.compare("front")==0){
            cout << que.Front() << '\n';
        }
        else if(cmd.compare("back")==0){
            cout << que.Back() << '\n';
        }
    }
}