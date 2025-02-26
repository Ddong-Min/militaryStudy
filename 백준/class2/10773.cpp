#include<iostream>

using namespace std;

class Stack
{
private:
    int top;
    int stack[100001];
public:
    Stack(int t) : top(t){}
    ~Stack(){}
    void push(int data){
        stack[top++] = data;
    }
    void pop(){
        if(top !=0) top--;
    }
    int countAll(){
        int sum=0;
        for(int i=0; i<top; i++){
            sum+=stack[i];
        }
        return sum;
    }
};

int main(){
    int k, data;
    Stack st(0);
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> data;
        if(data != 0) st.push(data);
        else st.pop();
    }
    int sum = st.countAll();
    cout << sum;
}