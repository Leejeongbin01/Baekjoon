#include <iostream>
#include <queue>
using namespace std;

int N,M;
int arr[102][102];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int ans = 0;

int bfs(int a,int b)
{
    queue<pair<int,pair<int,int>>> q; 
    q.push({a,{b,1}});
    arr[a][b]=0;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second.first;
        int cnt = q.front().second.second;
        if(x==N && y==M){
            return cnt;
        }
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>0 && ny>0 && nx<=N && ny<=M){
                if(arr[nx][ny]==1){
                    arr[nx][ny]=0;
                    q.push({nx,{ny,cnt+1}});
                }
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        string str; cin >> str;
        for(int j=1; j<=M; j++){
            arr[i][j] = str[j-1]-'0';
        }
    }

    cout << bfs(1,1);
    return 0;
}