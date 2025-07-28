#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
long long K;
vector<int> g[100001];
int indegree[100002];
queue<int> orderG;
long long ans[100002];

void setOrder()
{
    queue<int> q;
    for(int i=1; i<=N; i++){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        orderG.push(tmp);

        for(int i=0; i<g[tmp].size(); i++){
            int nx = g[tmp][i];
            indegree[nx]--;
            if(indegree[nx]==0) q.push(nx);
        }
    }

    /*
    while(!orderG.empty()){
        cout << orderG.front() << " ";
        orderG.pop();
    }
    cout << "\n";
    */
}

void divTask()
{
    long long now;
    ans[1]=K;
    while(!orderG.empty()){
        now = orderG.front();
        orderG.pop();
        cout << now << " ";
        if(g[now].size()){
        for(int i=0; i<g[now].size(); i++){
            long long tmp = g[now][i];
            ans[tmp] += ans[now]/g[now].size();
        }

        for(int i=0; i<ans[now]%g[now].size(); i++){
            long long tmp = g[now][i];
            ans[tmp]+=1;
        }
    }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. input
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        int num; cin >> num;
        while(num--){
            int a; cin >> a;
            g[i].push_back(a);
            indegree[a]++;
        }
    }

    // 2. task 순서 지정. 
    setOrder();

    // 3. 배분 시작
    divTask();

    return 0;
}