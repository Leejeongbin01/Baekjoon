#include <iostream>
#include <queue>
using namespace std;

int M,N;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int arr[1002][1002];
queue<pair<int,pair<int,int>>> q;

void bfs()
{
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>0 && ny>0 && nx<=N && ny<=M){
                if(arr[nx][ny]==0){
                    arr[nx][ny]=cnt;
                    q.push({nx,{ny,cnt+1}});
                }
            }
        }
    }    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> arr[i][j];
            if(arr[i][j]==1){
                q.push({i,{j,1}});
            }
        }
    }

    bfs();
    int ans = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            //cout << arr[i][j] << " ";
            if(arr[i][j]==0){
                cout << -1;
                return 0;
            }

            ans = max(ans, arr[i][j]);
        }
    }
    
    if(ans==1){
        ans = 0;
    }
    cout << ans;
    return 0;
}