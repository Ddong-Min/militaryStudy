#include<iostream>

using namespace std;

int* tri;
int* route;
int n;
int Topdown(int depth, int now){
    if(depth == n) return tri[now];
    if(route[now] != 0) return route[now];
    int left = now + depth;
    int right = left +1;
    int leftWeight = Topdown(depth+1, left);
    int rightWeight = Topdown(depth+1, right);
    route[now] = tri[now]+max(leftWeight, rightWeight);
    return route[now];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int size = n*(n+1)/2;
    tri = (int*)malloc(sizeof(int)*(size+1));
    route = (int*)malloc(sizeof(int)*(size+1));
    for(int i=1; i<=size; i++){
        cin >> tri[i];
    }

    cout << Topdown(1, 1);
    
}