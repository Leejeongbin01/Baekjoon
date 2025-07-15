#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b)
{
    return a.first < b.first;
}

int main()
{
    int N; cin >> N;
    unordered_map<string, int> um;
    for(int i=0; i<N; i++){
        string str; cin >> str;
        string tmp="";
        int flag =0;
        for(int j=0; j<str.size(); j++){
            if(flag == 1){
                tmp += str[j];
            }

            if(str[j]=='.'){
                flag = 1;
            }
        }

        if(um.find(tmp) != um.end()){ // yes
            um[tmp]++;
        }
        else{
            um.insert({tmp, 1});
        }
    }

    vector<pair<string,int>> v(um.begin(), um.end());
    sort(v.begin(), v.end(), compare);

    for(auto e : v){
        cout << e.first << " " << e.second << endl;
    }

    return 0;
}