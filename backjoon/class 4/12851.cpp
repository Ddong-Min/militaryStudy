#include <iostream>
#include <algorithm>
#include<queue>
#include<vector>

using namespace std;
/*1번풀이 change visit value is true when the data is pushed into queue
   If the value has already been visited, do not push it into the queue. 
   However, if the current depth is equal to the previously computed minimal depth for that value, increment the count
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
}*/

/*풀이2 : The first solution is poor in how it handles counting.
It's more concise to mark a node as visited when it's popped from the queue, not when it's pushed,
because pushing shouldn't depend on whether the node has already been visited.

but this method is slower than first method

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    queue<pair<int, int>> q;

    bool isVisit[100001];
    fill(isVisit, isVisit+100001, false);
    cin >> N >> K;

    q.push(make_pair(N, 0));
    isVisit[N]=true;
    int count=0, time=100001;

    while(!q.empty()){
        auto now = q.front();
        q.pop();
        int value = now.first;
        int depth = now.second;

        isVisit[value]=true;
        int next[3] = {value+1, value-1, value*2};
        if(count == 0 && value == K){
            count++;
            time = depth;
        }
        else if(value == K && time == depth) count++;
        if(time < depth) break;
        for(int i=0; i<3; i++){ 
            if(next[i] >= 0 && next[i] <= 100000 && !isVisit[next[i]]){
                q.push(make_pair(next[i], depth+1));
            }
        }
    }
    cout << time << endl;
    cout << count;
    return 0;
}

*/


//근데 지금 보니까 풀이 1이 복잡하기는 해도 더 효율적인 풀이같음
/* 그이유는 일단 풀이2는 모든 경우를 다 확인해보지만, 풀이 1는 모든 경우를 다 확인하지는 않음
이게 무슨말이냐 하면 
만약 1->2->4 이런 경우와 3->2->4 이런 경우가 있다면 
풀이 1 은 2까지 가는 방법이 2가지 따라서 4까지도 2가지 이런느낌이고

풀이2는 4에 도달시 경우를 확인해보니 1->2->4가 있고, 3->2->4 가 있구나 라고 확인하는 경우

따라서 풀이 1은 원하는 값에 도달할 경우 2->4 한번만 확인하면 되지만
풀이 2는 4에 도달 후 두번 값을 확인함

이게 값이 커지면 더 큰 시간 차이가 발생
*/