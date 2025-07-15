#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<string, int> &a, pair<string,int> &b)
{
    if(a.second == b.second){
        if(a.first.length() == b.first.length()){
            return a.first < b.first;
        }
        else{
            return a.first.length() > b.first.length();
        }
    }

    else{
        return a.second > b.second;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; cin >> N >> M;
    unordered_map<string, int> um;
    for(int i=0; i<N; i++){
        string tmp; cin >> tmp;
        if(tmp.size() < M) continue;

        if(um.find(tmp)!=um.end()){ // find
            um[tmp]++;
        }
        else{
            um.insert({tmp,1});
        }
    }

    vector<pair<string,int>> v(um.begin(), um.end());
    sort(v.begin(), v.end(), compare);
    for(auto e : v){
        cout << e.first << "\n";
    }
    

    return 0;
}