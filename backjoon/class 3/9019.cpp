#include <iostream>
#include <utility>
#include <string>
using namespace std;

class Queue{
private: 
    int target;
    int rear=0;
    int front=0;
    pair<int, string> q[10000];
public:
    Queue(int a){
        target = a;
    }
    void push(pair<int, string> val){
        q[rear++]=val;
    }
    pair<int, string> pop(){
        return q[front++];
    }
    int funD(int val){
        val = (val*2)%10000;
        return val;
    }
    int funS(int val){
        if(val>=1) val--;
        else val = 9999;
        return val;
    }
    int funL(int val){
        if(val==0) return 0;
        int temp = val/1000;
        val -= temp*1000;
        val*=10;
        val+=temp;
        return val;
    }
    int funR(int val){
        int temp = val%10;
        val /= 10;
        val += temp*1000;
        return val;
    }
    bool empty(){
        return (rear == front ? true : false);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, a, b;
    cin >> T;
    while(T--){
        cin >> a >> b;
        bool isVisit[10000];
        for(int i=0; i<10000; i++) isVisit[i]=false;    
        Queue queue(b);
        queue.push(make_pair(a,""));
        isVisit[a]=true;
        
        while(!queue.empty()){
            auto parent = queue.pop();
            if(parent.first == b){
                cout << parent.second << '\n';
                break;
            }
            pair<int, string> child;
            child.first = queue.funD(parent.first);
            child.second = parent.second+"D";
            if(!isVisit[child.first]){
                queue.push(child);
                isVisit[child.first]=true;
            }
            child.first = queue.funS(parent.first);
            child.second = parent.second+"S";
            if(!isVisit[child.first]){
                queue.push(child);
                isVisit[child.first]=true;
            }
            child.first = queue.funL(parent.first);
            child.second = parent.second+"L";
            if(!isVisit[child.first]){
                queue.push(child);
                isVisit[child.first]=true;
            }
            child.first = queue.funR(parent.first);
            child.second = parent.second+"R";
            if(!isVisit[child.first]){
                queue.push(child);
                isVisit[child.first]=true;
            }
            
        }
    }
    return 0;
}