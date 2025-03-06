#include<iostream>
#include<vector>

using namespace std;

class Stack{
private :
    int top=-1;
    int stack[100001];
public :
    void push(int data){
        stack[++top] = data; 
    }
    void pop(){
        top--;
    }
    int topVal(){
        return stack[top];
    }
    bool empty(){
        return top >= 0 ? true : false;
    }
};

int main(){
    Stack st;
    int n,point=0,i, temp;
    
    cin >> n;
    
    vector<int> seq;
    vector<char> ans;

    for(i=0; i<n; i++){
        cin >> temp;
        seq.push_back(temp);
    }

    for(i=1; i<=n; i++){
        st.push(i);
        ans.push_back('+');
        while(st.empty() && st.topVal()==seq[point]){  
            //오류가 날수있으니 stack이 비어있나 확인하기
            st.pop();
            ans.push_back('-');
            point++;
        }
        if(st.empty() && st.topVal() > seq[point]){
            cout << "NO";
            break;
        }
    }
    if(i==n+1){
        for(int i=0; i<2*n; i++){
            cout << ans[i] << '\n';
        }   
    }
}