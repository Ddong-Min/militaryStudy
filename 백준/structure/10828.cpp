#include<iostream>
#include<cstring>
using namespace std;

struct Node{
    int data;
    Node* link;
};

struct Head{
    int Slen=0;
    Node* Tnode=nullptr;
};

void push(Head* head, int data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(head->Tnode == nullptr) newnode->link = nullptr;
    else newnode->link = head->Tnode;
    newnode->data = data;
    head->Tnode = newnode;
    head->Slen++;
}

void pop(Head* head){
    if(head->Tnode == nullptr) printf("-1\n");
    else{
        Node* temp = (Node*)malloc(sizeof(Node));
        temp = head->Tnode->link;
        printf("%d\n", head->Tnode->data);
        head->Tnode = temp;
        head->Slen--;
    }
}

void size(Head* head){
    printf("%d\n", head->Slen);
}

void top(Head* head){
    if(head->Tnode == nullptr) printf("-1\n");
    else printf("%d\n", head->Tnode->data);
}

void empty(Head* head){
    if(head->Tnode == nullptr) printf("1\n");
    else printf("0\n");
}

int main(){
    int itr;
    int data;
    Head* head = (Head*)malloc(sizeof(Head));
    scanf("%d", &itr);
    while(itr--){
        char cmd[6]; //cmd 크기를 5로하면 오류, 6부터 가능해진다.
        scanf("%s", cmd);
        printf("strcmp = %d", strcmp(cmd, "empty"));
        if(!strcmp(cmd, "push")) {
            scanf("%d", &data);
            push(head, data);
        }
        else if(!strcmp(cmd, "pop")) pop(head);
        else if(!strcmp(cmd, "size")) size(head);
        else if(!strcmp(cmd, "empty")) empty(head);
        else if(!strcmp(cmd, "top")) top(head);
    }
}
/*문자열은 마지막에 널문자가 포함되야하는데 cmd[5]로하면 empty 명령에서
null문자가 포함될 자리가 없음 따라서 최소 6으로 크기를 지정해야함*/