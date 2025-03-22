#include <iostream>
#include <algorithm>
using namespace std;
int* trees;
int N, M;

int binarySearch(int start, int end){
    if(start > end) return 0;
    int mid= (start+end)/2;
    long long sum=0;
    for(int i=0; i<N && trees[i]>mid; i++){
       sum += trees[i]-mid;
    }
    if(sum >= M) return max(mid, binarySearch(mid+1, end));
    else return binarySearch(start, mid-1);
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    trees = (int*)malloc(sizeof(int)*N);

    for(int i=0; i<N; i++){
        cin >> trees[i];
    }
    sort(trees, trees+N, greater<>());
    cout << binarySearch(0,trees[0]);
}