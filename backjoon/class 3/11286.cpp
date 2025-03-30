#include <iostream>
#include <cmath>

using namespace std;

class Heap{
private:
    int heapsize=0;
    int tree[100001];
public:
    void push(int data){
        heapsize++;
        int parent = heapsize/2;
        int child = heapsize;
        while((parent >= 1 && (abs(tree[parent]) > abs(data)) || 
                           (abs(tree[parent]) == abs(data) && tree[parent] > data))){
            tree[child] = tree[parent];
            child = parent;
            parent = child/2;
        } 
        tree[child] = data;
    }

    void pop(){
        if(empty()){
            cout << 0 << '\n';
            return;
        }

        int parent = 1,  child = 2;
        cout << tree[parent] << '\n';
        
        int target =tree[heapsize];
        while(child < heapsize){
            if((child+1 < heapsize && abs(tree[child]) > abs(tree[child+1])) 
                || (abs(tree[child]) == abs(tree[child+1]) && tree[child] > tree[child+1])){
                child++;
            }
            if((abs(target) > abs(tree[child])) || (abs(target) == abs(tree[child]) && target > tree[child])){ //앞에 abs(tree[child])에서 abs안함 ..
                tree[parent]=tree[child];
                parent = child;
                child = 2*parent;
            }
            else break;
        }
        tree[parent] = target;
        heapsize--;
    }
    bool empty(){
        return heapsize > 0 ? false : true;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, data;
    cin >> n;
    Heap heap;
    
    while(n--){
        cin >> data;
        if(data != 0) heap.push(data);
        else heap.pop();
    }
    return 0;
}