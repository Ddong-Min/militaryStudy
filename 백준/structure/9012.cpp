#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
    int n, left=0;
    int right = 0;
    string c;
    cin >> n;  
    cin.ignore();  
    for(int i=0; i<n; i++){
        getline(cin, c);
        cout << c << endl;
        if(left == right) cout << "YES" << endl;
        else cout << "NO" << endl;
        left = right = 0;
    } 
    return 0;
}
