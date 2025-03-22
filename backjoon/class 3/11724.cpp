#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> v;
vector<bool> isVisit;

void DFS(int n){
    isVisit[n]=true;

    for(int i=0; i<v[n].size(); i++){
        int next = v[n][i];
        if(!isVisit[next]) DFS(next);
    }
}

int main(){
    int N, M, s, e, count=0;

    cin >> N >> M;

    v.assign(N+1, vector<int>(0,0));
    isVisit.assign(N+1, false);
    while(M--){
        cin >> s >> e;
        v[s].emplace_back(e);
        v[e].emplace_back(s);
    }

    for(int i=1; i<=N; i++){
        if(!isVisit[i]){
            count++;
            DFS(i);
        }
    }
    cout << count;
}