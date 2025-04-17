#include<iostream>
#include<utility>
#include<cstring>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int map[502][502];
bool isVisit[502][502];
int answer=0;
void DFS(pair<int, int> block, int cnt, int weight){
    cnt++;
    weight+=map[block.first][block.second];
    if(cnt==4){
        if(answer < weight) answer = weight;
        return;
    }
    for(int i=0; i<4; i++){
        pair<int, int> next;
        next.first = block.first+dy[i];
        next.second = block.second+dx[i];
        if(map[next.first][next.second]!=0 && !isVisit[next.first][next.second]){
            isVisit[next.first][next.second]=true;
            DFS(next, cnt, weight);
            isVisit[next.first][next.second]=false;
        }
    }
    weight-=map[block.first][block.second];
    cnt--;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int weight = 0;
    int max =0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];
        }
    }
    memset(isVisit, false, sizeof(isVisit));
    for(int y=1; y<=N; y++){
        for(int x=1; x<=M; x++){
            isVisit[y][x]=true;
            DFS(make_pair(y,x), 0, 0);
            isVisit[y][x]=false;
            for(int i=0; i<4; i++){
                weight=map[y][x];
                for(int j=0; j<4; j++){
                    if(i!=j){
                        int tx = x+dx[j];
                        int ty = y+dy[j];
                        weight+=map[ty][tx];
                    }
                }
                if(answer < weight) answer=weight;
            }
            
        }
    }
    
    cout << answer;

}

