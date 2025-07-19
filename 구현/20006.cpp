#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, string> &a, pair<int, string> &b)
{
    return a.second < b.second;
}

int main()
{
    int P,M; cin >> P >> M;
    vector<pair<int,string>> v;
    bool visit[501] = {0};
    for(int i=0; i<P; i++){
        int a;
        string c;
        cin >> a >> c;
        v.push_back({a,c});
    }
    
    if(M==1){
        for(int i=0; i<P; i++){
            cout << "Started!" << endl;
            cout << v[i].first << " " << v[i].second << endl;
        }
        return 0;
    }

    for(int i=0; i<P; i++){
        if(visit[i]==true) continue;
        int lv = v[i].first;
        visit[i]=true;
        int count = 0;
        vector<pair<int,string>> save;
        save.push_back({v[i].first, v[i].second});
        for(int j=i+1; j<P; j++){
            if(visit[j]==false){
                int lv_tmp = v[j].first;
                if(abs(lv-lv_tmp) <= 10){
                    visit[j]=true;
                    count++;
                    save.push_back({v[j].first, v[j].second});
                    if(count==(M-1)) break;
                }
            }
        }

        // cout << "count " << count << endl;
        sort(save.begin(), save.end(), cmp);
        if(count==(M-1)){
            cout << "Started!" << endl;
            for(int j=0; j<=count; j++){
                cout << save[j].first << " " << save[j].second << endl;
            }
        }
        else{
            cout << "Waiting!" << endl;
            
            for(int j=0; j<save.size(); j++){
                cout << save[j].first << " " << save[j].second << endl;
            }
        }
    }
    
    return 0;
}