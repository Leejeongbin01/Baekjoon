#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

vector<int> vec1;
vector<int> vec2;
vector<int> g[1001];
int visit[1001];

void bfs(int start)
{
    visit[start]=1;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        vec2.push_back(tmp);
        for(int i=0; i<g[tmp].size(); i++){
            if(visit[g[tmp][i]] == 0){
                q.push(g[tmp][i]);
                visit[g[tmp][i]]=1;
            }
        }
    }
}

void dfs(int start)
{
    visit[start]=1;
    vec1.push_back(start);
    
    for(int i=0; i<g[start].size(); i++){
        if(visit[g[start][i]]==0){
            dfs(g[start][i]);
        }
    }
}

int main()
{
    int N,M,V;
    cin >> N >> M >> V;

    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        
        g[a].push_back(b);        
        g[b].push_back(a);        
    }

    for(int i=1; i<=N; i++){
        sort(g[i].begin(), g[i].end());
    }

    dfs(V);
    memset(visit,0,sizeof(visit));
    bfs(V);

    for(int i=0; i<vec1.size(); i++){
        cout << vec1[i] << " ";
    }
    cout<<endl;
    
    for(int i=0; i<vec2.size(); i++){
        cout << vec2[i] << " ";
    }
    cout<<endl;

    return 0;
}