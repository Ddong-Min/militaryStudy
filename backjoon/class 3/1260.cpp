#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> tree;
vector<bool> isVisit;
queue<int> q;

void DFS(int V){
    cout << V << " ";
    isVisit[V]=true;
    for(int i=0; i < tree[V].size(); i++){
        if(!isVisit[tree[V][i]]) DFS(tree[V][i]);
    }
}

void BFS(){
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i=0; i<tree[node].size();i++){
            int next = tree[node][i];
            if(!isVisit[next]){
                q.push(next);
                isVisit[next]=true;
            }
        }
    }
}

int main() {
    int N, M, V, s, e;
    cin >> N >> M >> V;
    tree.assign(N+1, vector<int>(0,0));
    while(M--){
        cin >> s >> e;
        tree[s].emplace_back(e);
        tree[e].emplace_back(s);
    }
    for(int i=1; i<=N; i++){
        sort(tree[i].begin(), tree[i].end()); //vector front와 begin차이
    }
    
    isVisit.assign(N+1, false);
    DFS(V);
    cout << endl;
    
    isVisit.assign(N+1, false);
    q.push(V);
    isVisit[V]=true;
    BFS();
    return 0;
}