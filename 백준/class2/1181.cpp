#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
void quickSort(vector<string>& v, int start, int end){
    int pivot = start;
    int i = start+1, j=end;
    if(start>=end) return;
    while(i<=j){ //바보같이 i>j로 했었음 다시 말하지만 while문 조건은 안에 들어갈 조건이다
        while(v[pivot].length() >= v[i].length() && i<=end){
            if(v[pivot].length() == v[i].length()){
                if(v[pivot].compare(v[i]) >= 0) i++;
                else break;
            }
            else i++;
        }
        while(v[pivot].length() <= v[j].length() && j>start){
            if(v[pivot].length() == v[j].length()){
                if(v[pivot].compare(v[j]) <= 0) j--;
                else break;
            }
            else j--;
        }  

        if(i > j){
            string stemp = v[pivot];
            v[pivot] = v[j];
            v[j] = stemp;
        }
        else{
            string stemp = v[i];
            v[i] = v[j];
            v[j] = stemp;
        }
    }
    quickSort(v, start, j-1);
    quickSort(v, j+1, end);
}

int main(){
    int n;
    cin >> n;
    string s;
    vector<string> v;
    for(int i=0; i<n;){
        cin >> s;
        if(find(v.begin(), v.end(), s) == v.end()){
            v.push_back(s);
            i++;
        }
        else n--;
    }
    quickSort(v, 0, n-1);

    for(int i=0; i<n; i++){
        cout << v[i] << endl;
    }

}

*/
struct Fuxk
{
    string m;
    int len;
}fuxx[20001];

/*1이면 두개를 바꾸는거임 sort함수에서 */
bool Shit(Fuxk& fuxA, Fuxk& fuxB){
    if(fuxA.len == fuxB.len) return fuxA.m < fuxB.m; //A문자가 사전식으로 더 낮은순위면 1
    return fuxA.len < fuxB.len; //B문자열이 더 길면 1, 아니면 0
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> fuxx[i].m;
        fuxx[i].len = fuxx[i].m.length();
    }
    sort(fuxx, fuxx+n, Shit); //sort함수의 마지막 부분에 정렬기준을 추가해줄 수 있음
    string prev="";
    for(int i=0; i<n; i++){
        if(fuxx[i].m == prev) continue;
        else{
            cout << fuxx[i].m << endl;
        }
        prev=fuxx[i].m;
    }
}

//https://www.acmicpc.net/source/81196005
//https://www.acmicpc.net/source/82742151