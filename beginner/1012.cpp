#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T;
int M,N,K;
int g[51][51];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int cnt;

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x,y});
    g[x][y]=0;
    cnt++;

    while(!q.empty()){
        int tmpX = q.front().first;
        int tmpY = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = tmpX + dx[i];
            int ny = tmpY + dy[i];
            if(nx>=0 && ny>=0 && nx<M && ny<N){
                if(g[nx][ny]==1){
                    g[nx][ny]=0;
                    q.push({nx,ny});
                    cnt++;
                }
            }
        }
    }
}

int main()
{
    cin >> T;
    while(T--){
        cin >> M >> N >> K;
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                g[i][j]=0;
            }
        }
        
        for(int i=0; i<K; i++){
            int a,b; cin >> a >> b;
            g[a][b]=1;
        }

        int ans = 0;
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                if(g[i][j]==1){
                    cnt = 0;
                    bfs(i,j);
                    if(cnt!=0){
                        ans++;
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}