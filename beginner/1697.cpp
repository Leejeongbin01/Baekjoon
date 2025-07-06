#include <iostream>
#include <queue>
using namespace std;
bool visit[100010];
int main()
{
    int N,K; cin >> N >> K;
    queue<pair<int,int>> q;
    

    q.push({N,0});
    while(!q.empty()){
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(x==K){
            cout<<cnt<<endl;
            break;
        }
        int x1 = x-1;
        int x2 = x+1;
        int x3 = 2*x;
        if(x1 >= 0 && !visit[x1]){
            visit[x1]=1;
            q.push({x1,cnt+1});
        }

        if(x2 <=K && !visit[x2]){
            visit[x2] = 1;
            q.push({x2,cnt+1});
        }

        if(x3 <= K+1 && !visit[x3]){
            visit[x3] =1;
            q.push({x3,cnt+1});
        }
    }

    return 0;
}