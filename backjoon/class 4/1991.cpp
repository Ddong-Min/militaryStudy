#include<iostream>
#include<vector>

using namespace std;
vector<pair<char, char>> v(26);
void preOrder(char val){
    if(val == '.') return;
    cout << val;
    preOrder(v[val].first);
    preOrder(v[val].second);
}
void inOrder(char val){
    if(val == '.') return;

    inOrder(v[val].first);
    cout << val;
    inOrder(v[val].second);
}
void postOrder(char val){
    if(val == '.') return;
    postOrder(v[val].first);
    postOrder(v[val].second);
    cout << val;
}

int main(){
    int n;
    cin >> n;
    char val, left, right;
    while(n--){
        cin >> val >> left >> right;
        v[val] = make_pair(left, right);
    }
    preOrder('A');
    cout << '\n';
    inOrder('A');
    cout << '\n';
    postOrder('A');
}
//자세한 풀이 설명은 노션 참조

/* 바보 풀이
#include <iostream>
#include <queue>
using namespace std;

struct Node{
    char val;
    Node* left;
    Node* right;
};

void preOrder(Node* now){
    if(now == nullptr){
        return;
    }
    cout << now->val;
    preOrder(now->left);
    preOrder(now->right);
}
void midOrder(Node* now){
    if(now == nullptr){
        return;
    }
    midOrder(now->left);
    cout << now->val;
    midOrder(now->right);
}
void postOrder(Node* now){
    if(now == nullptr){
        return;
    }
    postOrder(now->left);
    postOrder(now->right);
    cout << now->val;

}

int main() {
    int n;
    char val, left, right;
    cin >> n;
    queue<Node*> q;
    
    Node* root = new Node;
    root->val = 'A';
    root->left = nullptr;
    root->right=nullptr;
    q.push(root);
    while(n--){
        Node* now = q.front();
        q.pop();
        cin >> val >> left >> right;
        while(now->val != val){
            q.push(now);
            now = q.front();
            q.pop();
        }
    
        if(left != '.'){
        Node* next = new Node;
        next->val = left;
        next->left = nullptr;
        next->right=nullptr;
        now->left = next;
        q.push(next);
        }
        if(right != '.'){
            Node* next = new Node;
            next->val = right;
            next->left = nullptr;
            next->right=nullptr;
            now->right = next;
            q.push(next);
        }   
    

    }

    preOrder(root);
    cout << '\n';
    midOrder(root);
    cout << '\n';    
    postOrder(root);
    return 0;
}

*/