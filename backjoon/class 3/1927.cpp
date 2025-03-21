#include <iostream>

using namespace std;

class Queue{
private:
    int rear=0;
    int* q;
public:
    Queue(int size){
        q = (int*)malloc(sizeof(int)*(size));
    }
    ~Queue(){
        free(q);
    }
    void push(int data){
        rear++;
        int i=rear;
        while((i!= 1) && data<q[i/2]){
            q[i]=q[i/2];
            i/=2;
        }
        q[i]=data;
    }
    void pop(){
        if(!empty()){
            cout << 0 << '\n';
            return;
        }
        int parent = 1, child=2, temp;
        cout << q[parent] << '\n';
        temp = q[rear];
        /*temp계산하는 걸 처음에 while문 안에 넣었더니
        heap에 두개의 값만 들어간 경우 child =2/ rear=2라서 while문 안에
        못들어가서 temp에 더미데이터가 q[parent]ㄹ 들어가서 오류발생
        이런거 조심하자
        */ 
        while(child < rear){
            if(child+1 <rear && q[child] > q[child+1]) child++;
            if(temp <= q[child]) break;
            q[parent] = q[child];
            parent = child;
            child *=2;
        }
        q[parent] = temp;    
        rear--;
    }
    /* pop할때 알고리즘이 살짝 가독성이 많이 떨어지는것 같다.
    그리고 마지막 값을 q[1]에 넣고 계속 더 작은값이 있으면 child랑 값을 바꿔가면서
    내려가는거 보다 들어갈 위치를 찾은 후에 한번만 입력하는게 더 효과적일거같다.
    따라서 위에 있는 코드가 해당 코드이다.
    void pop(){
        if(!empty()) cout << 0 << '\n';
        else{
            cout << q[1] << '\n';
            q[1]=q[rear];
            rear--;
            for(int i=1; i<=rear/2;){
                int min = i;
                if(q[min] > q[2*i]) min = 2*i;
                if(q[min] > q[2*i+1]) min = 2*i+1;
                if(min == i) break;
                int temp = q[min];
                q[min]=q[i];
                q[i] = temp;
                i=min;
            }         
        }
    }
    */
    int empty(){
        return rear;
    }
    
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, data;
    cin >> N;
    Queue queue(N+1);
    while(N--){
        cin >> data;
        if(data) queue.push(data);
        else queue.pop();
    }
}