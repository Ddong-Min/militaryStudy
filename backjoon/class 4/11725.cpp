#include<iostream>
#include<vector>

using namespace std;

class Queue{
private:
    int rear=0;
    int front = 0;
    int size;
    int* q;
public:
    Queue(int N){
        size=N;
        q=(int*)malloc(sizeof(int)*size);
    }
    ~Queue(){
        free(q);
    }
   void push(int data) {
        q[rear] = data;
        rear = (rear + 1) % size;
    }

    int pop() {
        int data = q[front];
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

    int N, s, e;
    cin >> N;

    vector<vector<int>> graph;
    vector<bool> isVisited;
    int pNode[N+1]={};
    graph.assign(N + 1, vector<int>(0, 0));
    isVisited.assign(N + 1, false);
    for(int i=0; i<N; i++){
        cin >> s >> e;
        graph[s].emplace_back(e);
        graph[e].emplace_back(s);
    }
    
    int parent = 1;
    Queue queue(N);
    queue.push(parent);
    isVisited[parent] = true;
    while(!queue.empty()){
        parent = queue.pop();
        for(int i=0; i<graph[parent].size(); i++){
            int next = graph[parent][i];
            if(!isVisited[next]){
                queue.push(next);
                isVisited[next]=true;
                pNode[next]=parent;
            }
        }
    }

    for(int i=2; i<=N; i++){
        cout << pNode[i] << '\n';
    }
    
}
