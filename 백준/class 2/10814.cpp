#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

struct Info{
    int age;
    string name;
    int num=0;
}info[100001];

void heapify(int index, int heapsize){
    int small = index;
    int lindex = 2*index+1;
    int rindex = 2*index+2;

    if(lindex < heapsize && info[small].age >= info[lindex].age){
        if(info[small].age == info[lindex].age && 
            info[small].num < info[lindex].num);
        else small = lindex;
    }
    if(rindex < heapsize && info[small].age >= info[rindex].age){
        if(info[small].age == info[rindex].age && 
            info[small].num < info[rindex].num);
        else small = rindex;
    }

    if(small != index){
        Info temp = info[index];
        info[index]=info[small];
        info[small]=temp;
        heapify(small, heapsize);
    }

}

void heapSort(int n){
    for(int i=n/2-1; i>=0; i--){
        heapify(i, n);
    }
    for(int i=n-1; i>=0; i--){
        cout << info[0].age << " " << info[0].name << '\n';
        if(i!=0){
            Info temp = info[0];
            info[0]=info[i];
            info[i]=temp;
            heapify(0,i); //heapify(0,i-1)로 해서 틀림,
            //원래는 사이즈가 n 그다음에 for문오자마자 -1하고 점점 줄여가서
            //i-1로 더 줄일필요가없어
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> info[i].age >> info[i].name;
        info[i].num = i+1;
    }

    heapSort(n);
}

