#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int W,N;
vector<pair<int,int>> v;

bool cmp(pair<int,int> &a, pair<int,int> &b)
{
    return a.second > b.second;
}

int main()
{
    // 1. input
    cin >> W >> N;
    for(int i=0; i<N; i++){
        int a,b;
        cin >> a >> b;
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
    
    // 3. cal.
    int result = 0;
    int idx = 0;
    while(W>=0){
        int a = v[idx].first;
        int b = v[idx].second;

        if(W >= a){ // 배낭이 보물보다 더 크면..
            result += a*b;
            W -= a;
        }
        else{   // 배낭이 보물보다 더 작으면. 
            result += W*b;
            W = 0;
        }

        idx++;
        //cout << idx << " " << result << "\n";
    }

    cout << result << "\n";
    return 0;
}