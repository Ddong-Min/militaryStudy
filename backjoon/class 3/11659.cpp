#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, i, j, data;
    cin >> N >> M;
    
    vector<int> number;
    number.push_back(0);
    while(N--){
        cin >> data;
        number.push_back(data+number.back());
    }

    while(M--){
        cin >> i >> j;
        cout << number[j]-number[i-1] << '\n';
    }
    return 0;
}