#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N,M;
int input1, input2;
vector<int> v[101];
bool visit[101];
int cnt;
    bool flag = false;

void bfs(int x)
{
    queue<pair<int,int>> q;
    q.push({x,1});
    visit[x]=true;

    while(!q.empty()){
        int tmpX = q.front().first;
        int tmpCnt = q.front().second;
        q.pop();

        if(tmpX==input2){
            cnt = tmpCnt;
            return;
        }

        for(int i=0; i<v[tmpX].size(); i++){
            if(visit[v[tmpX][i]]==false){
                visit[v[tmpX][i]]=true;
                q.push({v[tmpX][i], tmpCnt+1});

            }
        }
    }
    cnt = -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> input1 >> input2;
    cin >> M;

    for(int i=0; i<M; i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs(input1);
    if(cnt==-1){
        cout << -1 << "\n";
    }
    else{
        cout << cnt -1 << "\n";
    }
    return 0;
}