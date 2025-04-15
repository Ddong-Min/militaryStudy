#include <iostream>
using namespace std;

void backTracking(int N, int M, int start, int* data) {
    if(M == 0) {
        for(int i = 1; i <= N; i++) {
            if(data[i-1]) cout << i << " ";  // 1-based 인덱스 출력
        }
        cout << endl;
        return;
    }

    for(int i = start; i <= N; i++) {
        data[i-1] = 1;  
        backTracking(N, M - 1, i + 1, data);
        data[i-1] = 0; 
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    int data[10]={};
    backTracking(N, M, 1, data);  
    return 0;
}
