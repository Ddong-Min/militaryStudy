#include <iostream>

using namespace std;
class Queue{
private:
    int front=0;
    int rear=0;
    int q[100001];
public:
    void push(int data){
        q[rear++]=data;
    }
    int pop(){
        return q[front++];
    }
    bool empty(){
        return front==rear ? true : false;
    }
};

int main() {
    int N, K;
    Queue queue;
    bool isVisit[100001];
    int depth[100001];
    fill_n(isVisit, 100001, false);
    cin >> N >> K;

    queue.push(N);
    depth[N]=0;
    while(!queue.empty()){
        int now = queue.pop();
        if(now == K){
            cout << depth[now];
            break;
        }
        int next[3] = {now+1, now-1, now*2};
            
        for(int i=0; i<3; i++){
            int nval = next[i];
            if(nval >=0 && nval <=100000){
                if(!isVisit[nval]){
                    isVisit[nval]=true;
                    queue.push(nval);
                    depth[nval]=depth[now]+1;
                }   
            }
        }
    }
    
    return 0;
}