#include<iostream>

using namespace std;

struct Q{
    int index;
    int weight;
};

class Queue{
private:
    int front=0;
    int rear=0;
    int size=101;
    Q queue[101];
public:
    void push(int data, int idx){
        rear = (rear+1)%size;
        queue[rear].weight = data;
        queue[rear].index = idx;
    }
    int pop(int index){
        int count=0;
        while(1){
            int key = (front+1) % size;
            int maxWeight = queue[key].weight;
            for(int i = (front+1) % size; i != (rear+1) % size; i = (i+1) % size) {
                if(queue[i].weight > maxWeight) {
                    maxWeight = queue[i].weight;
                    key = i;
                }
            }
            //앞에꺼가 가장크지 않을때 뒤로보내기 
            if(key != (front+1)% size){ 
                /* tq key != front+1로 해서 틀림   
                원형큐니까 key != (front+1)%size로 해야 오류없음 */
                front = (front + 1) % size;
                rear = (rear + 1) % size;
                queue[rear] = queue[front];
            }
            //앞에꺼가 가장클때
            else {
                count++;
                front = (front+1)%size;
                if(queue[front].index == index) { //ㅅㅂ ==이라 해야하는데 =이라했어
                    return count;
                
                }
            }
        }
    }
};

int main(){
    int T, n, m,w;

    cin >> T;

    while(T--){
        cin >> n >> m;
        Queue que;
        for(int i=0; i<n; i++){
            cin >> w;
            que.push(w, i);
        }
        cout << que.pop(m) << '\n';
    }
}