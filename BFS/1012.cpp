#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int T,M,N,K;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int arr[51][51];

void bfs(int x, int y)
{
    queue<pair<int,int>> q;
    arr[x][y]=0;
    q.push({x,y});
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = a+dx[i];
            int ny = b+dy[i];
            if(nx>=0 && ny>=0 && nx<M && ny<N){
                if(arr[nx][ny]==1){
                    arr[nx][ny]=0;
                    q.push({nx,ny});
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
    
    cin >> T;
    while(T--){
        cin >> M >> N >> K;
        memset(arr,0,sizeof(arr));
        for(int i=0; i<K; i++){
            int a,b; cin >> a >> b;
            arr[a][b]=1;
        }

        int cnt = 0;
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                if(arr[i][j]==1){
                    bfs(i,j);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}