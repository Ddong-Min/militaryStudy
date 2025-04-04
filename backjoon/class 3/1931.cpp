#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> schedule;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, start, end;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> start >> end;
        schedule.push_back(make_pair(start,end));
    }

    sort(schedule.begin(), schedule.end(), [](pair<int, int> a1, pair<int, int> a2)
        {
            if(a1.second < a2.second) return true;
            else if(a1.second == a2.second && a1.first < a2.first) return true;
            return false;
        });
    int endtime=0, count =0;
    for(int i=0; i<N; i++){
        if(schedule[i].first >= endtime){
            count++;
            endtime = schedule[i].second;
        }
    }

    cout << count;
    
    return 0;
}