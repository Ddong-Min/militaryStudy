#include<iostream>

using namespace std;

template<typename T>
class Stack
{
private:
    T stack[101];
    int top;
public:
    Stack(int t) : top(t){
    }
    ~Stack(){}
    void push(T data){
        stack[top++] = data;
    }
    void pop(){
        if(top!=0) top--;
    }
    T searchTop(){
        return stack[top-1]; //top-1을 넣었어야 했는데 top을 넣음 
        //push에서 데이터를 top에 넣고 ++해줬으니 top-1이 데이터가 있는 가장 마지막 부분
    }
    int topVal(){
        return top;
    }
};

int main(){
    while(1){
        Stack<char> st(0);
        char c[101];
        cin.getline(c,101);
        if(c[0] == '.') break;
        int i=0; //첨에 1로함 위에서 0번은 확인했다고 생각함 근데 이건 .인지 확인한거지
        //괄호여부를 확인한게 아니잖아
        while(1){
            if(c[i]=='(' || c[i]=='['){
                st.push(c[i]);
            }
            else if(c[i]==')'){
                char temp= st.searchTop();
                if(temp == '(') st.pop();
                else st.push(c[i]);
            }
            else if(c[i]==']'){ 
                char temp = st.searchTop();
                if(temp == '[') st.pop();
                else st.push(c[i]);
            }
            i++;
            if(c[i] == '.') break;
        }
        if(st.topVal()==0) cout << "yes" << endl;
        else cout << "no" << endl; 
    }
}