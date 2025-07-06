#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v[101];
bool visit[101];
int cnt;

void dfs(int x)
{
    if(visit[x] == true){
        return;
    }
    visit[x] = true;
    cnt++;
    for(int i=0; i<v[x].size(); i++){
        if(visit[v[x][i]]==false){
            dfs(v[x][i]);
        }
    }
}

int main()
{
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i=1; i<=N; i++){
        sort(v[i].begin(), v[i].end());
    }

    dfs(1);
    cout << cnt-1 <<endl;
    return 0;
}