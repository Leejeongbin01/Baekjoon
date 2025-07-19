#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

// 못풀었음. gpt 참고

map<string, vector<pair<string, int>>> node;

void dfs(string current, int& file_cnt, set<string>& file_types)
{
    for(auto& [name, type] : node[current]){
        if(type==0){
            file_cnt++;
            file_types.insert(name);
        }
        else{
            dfs(name, file_cnt, file_types);
        }
    }
}

vector<string> split_path(const string& path)
{
    vector<string> result;
    stringstream ss(path);
    string token;
    while(getline(ss, token, '/')){
        result.push_back(token);
    }
    return result;
}

int main()
{
    int N, M; cin >> N >> M;
    for(int i=0; i<N+M; i++){
        string parent, child;
        int check;
        cin >> parent >> child >> check;
        node[parent].push_back({child, check});
    }

    int Q; cin >> Q;
    while(Q--){
        string query; cin >> query;
        int file_cnt = 0;
        set<string> file_types;
        
        vector<string> folders = split_path(query);
        string cur = folders[0];
        for(int i=1; i<folders.size(); i++){
            string next = folders[i];
            for(auto& [child, type] : node[cur]){
                if(child == next && type==1){
                    cur = child;
                    break;
                }
            }
        }

        dfs(cur, file_cnt, file_types);
        cout << file_types.size() << " " << file_cnt << endl;        
    }

    return 0;
}