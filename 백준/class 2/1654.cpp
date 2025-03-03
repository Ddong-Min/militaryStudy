#include<iostream>

using namespace std;

int k, n;
int* elec;

bool fn(int mid){
    int sum=0;
    for(int i=0; i<k; i++){
        sum+=elec[i]/mid;
    }
    if(sum >= n) return true;
    else return false;
}

int upperbound(int low, int high){ //이걸 long long으로 하니 시간 초과 발생
    while(low <= high){
        int mid = low+(high-low)/2;
        if(mid==0) low=mid+1;
        else if(mid == 2147483647){ 
            /*mid==int 최고범위면 low = high둘다 최고범위인거
            이경우에는 f(n)이 true이면서 low가 high보다 크면서 정수범위 넘어선다
            그럼 막대기가 자르는 개수가 0개 즉 k보다 무조건 작아지므로 이런경우는 없음
            따라서 그냥 low를 return 
            */
            return low;
        }
        else if(fn(mid)) low = mid+1;
        else high = mid-1;
    }
    return low-1;
    /*처음에 low로 해서 틀림, 근데 생각해보면 upperbound니까
    원하는 값보다 큰 가장작은 값이 나오는거니
    low-1을 해줘야함*/
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int max;
    cin >> k >> n;
    elec = (int*)malloc(sizeof(int)*k);

    for(int i=0; i<k; i++){
        cin >> elec[i];
        if(max < elec[i]) max = elec[i];
    }
    cout << upperbound(0, max);
}