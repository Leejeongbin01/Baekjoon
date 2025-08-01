#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int,int>> v;

bool cmp(pair<int,int> &a, pair<int,int> &b)
{
    return a.second < b.second;
}

int main()
{
    // 1. input
    cin >> N;
    for(int i=0; i<N; i++){
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), cmp);
    
    // 2. check
    /*
    cout << "check\n";
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }
    */

    int end=0;
    int result = 0;
    for(int i=0; i<v.size(); i++){
        if(end <= v[i].first){
            // 3에 끝나는데, 3이상부터시작할 때
            end = v[i].second;
            result++;
        }
        else{
            // 3에 끝나는데, 2부터 시작할경우

        }
    }

    cout << result << "\n";
    return 0;
}