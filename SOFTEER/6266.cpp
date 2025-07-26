#include <iostream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

int N,M;
map<string,vector<pair<int,int>>> m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    
    for(int i=1; i<=N; i++){
        string str; cin >> str;
    }

    for(int i=1; i<=M; i++){
        string str; 
        int start, end;
        cin >> str >> start >> end;

        m[str].push_back({start,end});
    }

    for(auto it : m){
        bool visit[20];
        memset(visit,0,sizeof(visit));
        for(int i=0; i<it.second.size(); i++){
            int a = it.second[i].first;
            int b = it.second[i].second;

            if(b==18){
                for(int j=a; j<=b; j++){
                    visit[j]=true;
                }
            }
            else{
                for(int j=a; j<b; j++){
                    visit[j]=true;
                }
            }
        }

        for(int i=9; i<=18; i++){
            cout << visit[i] << " ";
        }
        cout << "\n";

        
    }
    return 0;
}