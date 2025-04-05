#include <iostream>
#include <cstring>

using namespace std;

class Deque{
private:
    int front=0; 
    int rear=0;
    bool isReverse = false;
    int* q;
public:
    Deque(int size){
        q=(int*)malloc(sizeof(int)*size);
    }
    ~Deque(){
        free(q);
    }
    void push(int data){
        q[rear++]= data;
    }
    void pop(){
        if(isReverse) rear--;
        else front++;
    }
    bool isEmpty(){
        return rear == front ? true : false;
    }
    void setReverse(){
        isReverse = !isReverse;
    }
    void print(){
        cout <<  "[";
        if(isReverse){
            for(int i=rear-1; i>=front; i--){
                if(i!=front) cout << q[i] <<",";
                else cout << q[i];
            }
        }
        else{
            for(int i=front; i<rear; i++){
                if(i!=rear-1) cout << q[i] <<",";
                else cout << q[i];
            }    
        }

        cout <<  "]" << '\n';
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,N;
    string cmd;

    cin >> T;

    while(T--){
        cin >> cmd;
        cin >> N;
        char seq[300001];
        Deque deque(N);
        cin >> seq;
        char *p_str = strtok(seq, ",[]");   
         while (p_str != NULL) {
            deque.push(atoi(p_str));
            p_str = strtok(NULL, ",[]");
        }

        for(int i=0; i<cmd.size(); i++){
            if(cmd[i]=='R') deque.setReverse();
            else{
                if(deque.isEmpty()){
                    cout << "error" << '\n';
                    break;
                }
                else{
                    deque.pop();
                }
            }
            if(i==(cmd.size()-1)) deque.print();
        }
    }
    return 0;
}