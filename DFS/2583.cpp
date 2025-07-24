#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
bool visit[1001];
vector<int> v[1001];

void dfs(int x)
{
    if(visit[x]==true){
        return;
    }

    visit[x]=true;
    for(int i=0; i<v[x].size(); i++){
        int tmp = v[x][i];
        if(visit[tmp]==false){
            //cout << "tmp : " << tmp << endl;
            dfs(tmp);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M; 
    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int ans = 0;
    for(int i=1; i<=N; i++){
        if(visit[i]==false){
            dfs(i);
            ans++;
        }
    }
    
    cout << ans << "\n";
    return 0;
}