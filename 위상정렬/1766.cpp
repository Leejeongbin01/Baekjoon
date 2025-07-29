#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
vector<int> g[32001];
int degree[32001];

void t_sort()
{
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=1; i<=N; i++){
        if(degree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int now = q.top(); 
        q.pop();
        cout << now << " ";

        for(int i=0; i<g[now].size(); i++){
            int tmp = g[now][i];
            degree[tmp]--;
            if(degree[tmp]==0){
                q.push(tmp);
            }
        }
    }

}

int main()
{
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        degree[b]++;
    }

    t_sort();
    cout << "\n";
    return 0;
}