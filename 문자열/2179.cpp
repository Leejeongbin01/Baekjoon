#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int N; cin >> N;
    map<string, vector<int>> m;
    set<string> check;
    vector<string> input;
    input.resize(N);
    int max_length = 0;

    for(int i=0; i<N; i++){
        string str; cin >> str;
        input[i] = str;
        if(check.find(str)!= check.end()) continue;
        check.insert(str);

        string tmp = "";
        for(int j=0; j<str.size(); j++){
            tmp += str[j];
            m[tmp].push_back(i);

            if(m[tmp].size() > 1 && max_length < tmp.length()){
                max_length = tmp.length();
            }
        }
    }

    int max_order = 1e9;
    string max_str = "";
    for(const auto& [key, value] : m){
        if(value.size() >= 2 && key.length() == max_length){
            if(value[0] < max_order){
                max_order = value[0];
                max_str = key;
            }
        }
    }

    cout << input[m[max_str][0]] << endl;
    cout << input[m[max_str][1]] << endl;
    return 0;
}