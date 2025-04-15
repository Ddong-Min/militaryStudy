#include<iostream>
#include<string>
#include<map>
using namespace std;

class priQue{
private:
    int sizeMax=0;
    int sizeMin=0;
    int* MaxHeap;
    int* MinHeap;
    map<int, int> cnt;
public:
    priQue(int n){
        MaxHeap = (int*)malloc(sizeof(int)*(n+1));
        MinHeap = (int*)malloc(sizeof(int)*(n+1));
    }
    ~priQue(){
        free(MaxHeap);
        free(MinHeap);
    }
    void push(int data){
        
        sizeMax++;
        sizeMin++;
        
        int child = sizeMax;
        int parent = child/2;
        cnt[data]++;
        while(child>1){
            if(MaxHeap[parent] < data){
                MaxHeap[child] = MaxHeap[parent];
                child = parent;
                parent = child/2;
            }
            else break;
        }
        MaxHeap[child]=data;
        child = sizeMin;
        parent = child/2;
        while(child>1){
            if(MinHeap[parent] > data){
                MinHeap[child] = MinHeap[parent];
                child = parent;
                parent = child/2;
            }
            else break;
        }
        MinHeap[child]=data;
    }
    void pop(int cmd){
        int parent = 1;
        int child = parent*2;
        if(cmd==1){
            if(cnt[MaxHeap[1]]!=0) cnt[MaxHeap[1]]--;
            int data = MaxHeap[sizeMax];
            while(child < sizeMax){
                if(child + 1 < sizeMax && MaxHeap[child] < MaxHeap[child+1]) child++;
                if(data < MaxHeap[child]){
                    MaxHeap[parent]=MaxHeap[child];
                    parent = child;
                    child = parent*2;
                }
                else break;
            }
            
            MaxHeap[parent] = data;
            sizeMax--;
        }

        else if(cmd==-1){
            if(cnt[MinHeap[1]]!=0) cnt[MinHeap[1]]--;
            int data = MinHeap[sizeMin];
            while(child < sizeMin){
                if(child + 1 < sizeMin && MinHeap[child] > MinHeap[child+1]) child++;
                if(data > MinHeap[child]){
                    MinHeap[parent]=MinHeap[child];
                    parent = child;
                    child = parent*2;
                }
                else break;
            }
            MinHeap[parent] = data;
            sizeMin--;
        }
    }

    bool empty(){
        if(sizeMax == 0 || sizeMin == 0) return true;
        else return false;
    }
    void organize(){
        while(sizeMin!=0 && cnt[MinHeap[1]]==0) pop(-1);
        while(sizeMax!=0 && cnt[MaxHeap[1]]==0) pop(1);

    }
    void printAnswer(){
        if(sizeMax == 0 || sizeMin == 0) cout <<"EMPTY"<<'\n';
        else cout <<MaxHeap[1] << " " << MinHeap[1] << '\n';

    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int n, data;
        cin >> n;
        string cmd;
        priQue queue(n);
        while(n--){
            cin >> cmd >> data;
            if(cmd == "I"){
                queue.push(data);
            }
            else{
                if(!queue.empty()) queue.pop(data);
                queue.organize(); 
            }
        }
        queue.organize();
        queue.printAnswer();
    }
}