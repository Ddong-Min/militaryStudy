#include<iostream>
#include<algorithm>
using namespace std;

struct Loc{
    int x;
    int y;
};

void heapify(Loc* loc, int index, int heapsize){
    int lindex = 2*index +1;
    int rindex = 2*index +2;
    int min = index;

    if (lindex < heapsize) {
        if (loc[lindex].x < loc[min].x || 
           (loc[lindex].x == loc[min].x && loc[lindex].y < loc[min].y)) {
            min = lindex;
        }
    }

    if (rindex < heapsize) {
        if (loc[rindex].x < loc[min].x || 
           (loc[rindex].x == loc[min].x && loc[rindex].y < loc[min].y)) {
            min = rindex;
        }
    }

    /*
    if(loc[min].x >= loc[lindex].x && lindex < heapsize){
        if(loc[min].x == loc[lindex].x 
            && loc[min].y < loc[lindex].y);
        else min=lindex;
    }
    if(loc[min].x >= loc[rindex].x && rindex < heapsize){
        if(loc[min].x == loc[rindex].x 
            && loc[min].y < loc[rindex].y);
        else min=rindex;
    }

    => 이건 segfualt가 나는 이유 : lindex < heapsize를 먼저 체크해야 하는데
    loc[min].x >= loc[lindex].x

    이걸 먼저해서 잘못된 접근이 발생

    그럼 아래처럼 바꾸면 될까? =>? 가능 &&앞에 먼저 체크하고
                            틀리면 뒤에 체크 안하나봐
    if(lindex < heapsize && loc[min].x >= loc[lindex].x){
        if(loc[min].x == loc[lindex].x 
            && loc[min].y < loc[lindex].y);
        else min=lindex;
    }
    if(rindex < heapsize && loc[min].x >= loc[rindex].x){
        if(loc[min].x == loc[rindex].x 
            && loc[min].y < loc[rindex].y);
        else min=rindex;
    }
    */
    if(min!=index){
        Loc temp = loc[min];
        loc[min] = loc[index];
        loc[index] = temp;
        heapify(loc,min, heapsize);
    }
}

void heapSort(Loc* loc, int n){
    for(int i=n/2-1; i>=0; i--){
        heapify(loc,i, n);
    }

    for(int i=n-1; i>=0; i--){
        cout << loc[0].x << " " << loc[0].y << '\n';
        if(i!=0){
            Loc temp = loc[0];
            loc[0] = loc[i];
            loc[i]=temp;
            heapify(loc,0, i);
        }
    }

}
int main(){
    int n;
    cin >> n;
    Loc* loc = new Loc[100001];
    for(int i=0; i<n; i++){
        cin >> loc[i].x >> loc[i].y;
    }

    /*method 1*/
    heapSort(loc, n);

    /*mothod 2
    //sort함수는 true면 그대로  false 면 변환 
    sort(loc, loc+n, [&](const Loc& a, const Loc& b) -> bool{
        if(a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });

    for(int i=0; i<n; i++){
        cout << loc[i].x << " " << loc[i].y <<'\n';
    }
        */

    delete[] loc;
}