#include<iostream>
#include<vector>

using namespace std;

void SelectSorting(vector<int>& v){
    int len = v.size();
    int min_index;
    for(int i=0; i<len-1; i++){
        min_index = i;
        for(int j=i+1; j<len; j++){
            if(v[min_index] > v[j]){
             min_index = j;   
            }
        }
        if(min_index != i){
            int temp = v[i];
            v[i] = v[min_index];
            v[min_index] = temp;
        }
    }
}
int main(){
    vector<int> v;
    int n, data;
    scanf("%d", &n);
    int i=n;

    while(i--){
        scanf("%d", &data);
        v.push_back(data);
    }

    SelectSorting(v);

    for(i=0; i<n;i++){
        printf("%d\n", v[i]);
    }
    return  0;
}