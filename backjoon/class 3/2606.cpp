#include <iostream>
#include <vector>
using namespace std;

int v,s, e, count=0;
vector<vector<int>> graph;
vector<bool> isVisit;

void DFS(int cur){
    isVisit[cur] = true;
    for(int i=0; i < graph[cur].size(); i++){
        int next = graph[cur][i];
        if(isVisit[next] == false){
            count++;
            DFS(next);
        }
    }
}

int main(){
    int n;
    cin >> v;
    cin >> n;
    graph.assign(v+1, vector<int>(0,0));
    isVisit.assign(v+1,false);
    
    for(int i=0; i<n;i++){
        cin >> s >> e;
        graph[s].emplace_back(e);
        graph[e].emplace_back(s);
    }

    DFS(1);
    
    cout << count;
}