#include<iostream>
#include<string>
using namespace std;

/*내식 풀이 근데 굳이 left right로 변수둘 필요
없었음 => 그냥 좌괄호면 + 우괄호면 - 하면 되는거

int main(int argc, char** argv)
{
    int n, left=0;
    int right = 0;
    string c;
    cin >> n;  
    cin.ignore();  
    for(int i=0; i<n; i++){
        getline(cin, c);
        for(int j=0; c[j]=='(' || c[j]==')'; j++){
            if(c[j]=='(') left++;
            else right++;
            if(left < right) break;
        }
        if(left == right) cout << "YES" << endl;
        else cout << "NO" << endl;
        left = right = 0;
    } 
    return 0;
}
*/

/*left right로 구분하지 않은 경우
근데 시간이랑 메모리 자체는 큰 차이가 나지 않음*/
int main(int argc, char** argv)
{
    int n, cnt=0;
    char c[51];
    scanf("%d", &n); 
    for(int i=0; i<n; i++){
        char *p = c;
        scanf("%s", p);  //getline에서 scanf로 바꾸니까 확실히 빨라짐 4ms -> 0m0525
        for(;*p && cnt >=0;){
            cnt+=*(p++) - '('? -1 : 1;
        }
        puts(!cnt ? "YES" : "NO"); //puts로 하는 cout으로 하든 시간차이는 큰 차이가 안남
        cnt=0;
    } 
    return 0;
}