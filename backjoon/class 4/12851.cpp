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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    Queue queue;
    int cnt[100001]={};
    int depth[100001];
    cin >> N >> K;

    queue.push(N);
    depth[N]=0;
    cnt[N]=1;
    int min = 100001;
    int now;
    while(!queue.empty()){
        now = queue.pop();
        //cout << now << " " << cnt[now] << endl;

        if(now == K){
            if(min > depth[now]){
                min = depth[now];
            }
        }
        if(depth[now] > min) break;
        int next[3] = {now+1, now-1, now*2};
            
        for(int i=0; i<3; i++){
            int nval = next[i];
            if(nval >=0 && nval <=100000){
                if(cnt[nval]==0){
                    cnt[nval]=cnt[now];
                    queue.push(nval);
                    depth[nval]=depth[now]+1;
                }
                else if(depth[nval] == (depth[now]+1)){
                    cnt[nval] += cnt[now];
                }
            }
        }
    }
    cout << min << '\n';
    cout << cnt[K];
    return 0;
}

//5 4 8 16 17
//5 10 9 18 17