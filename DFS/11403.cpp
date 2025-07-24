#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int ansArr[101][101];
vector<int> v[101];
bool visit[101];

void dfs(int x)
{
    for(int i=0; i<v[x].size(); i++){
        if(visit[v[x][i]]==false){
            visit[v[x][i]]=true;
            dfs(v[x][i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int a; cin >> a;
            if(a==1){
                v[i].push_back(j);
                //v[j].push_back(i);
            }
        }
    }

    for(int i=1; i<=N; i++){
        dfs(i);
        
        for(int j=1; j<=N; j++){
            if(visit[j]==false) ansArr[i][j]=0;
            else                ansArr[i][j]=1;
        }
        memset(visit,false,sizeof(visit));
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << ansArr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}