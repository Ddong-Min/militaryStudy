#include<iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int deck[n];
    for(int i=0; i<n; i++){
        cin >> deck[i];
    }
    int jack=0;
    int sum;
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                sum = deck[i]+deck[j]+deck[k];
                if(sum<=m && sum>jack) jack = sum;
            }
        }
    }
    cout << jack;
    
}