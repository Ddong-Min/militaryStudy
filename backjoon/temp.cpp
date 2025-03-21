#include<iostream>
#include<vector>

using namespace std;

int main(){
     vector<int> v{10,20,30,40,50};

     cout << v.front() << endl;

     v.front() = 100;

     cout << v[0] << endl;
}