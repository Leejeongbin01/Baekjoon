#include <iostream>
#include <queue>
using namespace std;

int N,M,K;
int arr[101][101];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int bfs(int a, int b)
{
    queue<pair<int,pair<int,int>>> q;
    q.push({a,{b,1}});
    arr[a][b]=0;

    int ans = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>0 && ny>0 && nx<=N && ny<=M){
                if(arr[nx][ny]==1){
                    arr[nx][ny]=0;
                    q.push({nx,{ny,cnt+1}});
                    ans++;
                }
            }
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    for(int i=0; i<K; i++){
        int a,b;
        cin >> a >> b;

        arr[a][b]=1;
    }

    int result=0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(arr[i][j]==1){
                int tmp = bfs(i,j);
                result = max(result, tmp);
            }
        }
    }

    cout << result;
    return 0;
}