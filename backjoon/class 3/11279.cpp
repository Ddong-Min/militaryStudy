#include<iostream>

using namespace std;

//MaxHeap class로 구현
class MaxHeap{
private:
    int heapsize=0;
    int* data;
public:
    MaxHeap(int N){
        data = (int*)malloc(sizeof(int)*N);
    }
    ~MaxHeap(){
        free(data);
    }
    void push(int value){
        heapsize++;
        int i;
        for(i=heapsize; i>1 && value > data[i/2]; i/=2){
            data[i] = data[i/2];
        }
        data[i]=value;
    }
    void pop(){
        if(!heapsize){
            cout << 0 << '\n';
            return;
        } 
        int parent = 1, child=2;
        cout << data[parent] << '\n';
        int temp = data[heapsize];
        while(child < heapsize){
            if(child+1 < heapsize && data[child+1] > data[child]) child++;
            if(temp > data[child]) break;
            data[parent] = data[child];
            parent = child;
            child = parent*2;
        }
        data[parent] = temp;
        heapsize--;
    }

};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, cmd;
    cin >> N;
    MaxHeap heap(N+1);

    while(N--){
        cin >> cmd;
        if(cmd) heap.push(cmd);
        else heap.pop();
    }
    return 0;
    
}