#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
int indegree[32001];
vector<int> g[32001];

void t_sort()
{
    queue<int> q;
    for(int i=1; i<=N; i++){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        cout << now << " ";

        for(int i=0; i<g[now].size(); i++){
            int tmp = g[now][i];
            indegree[tmp]--;
            if(indegree[tmp]==0){
                q.push(tmp);
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        indegree[b]++;
    }

    t_sort();
}