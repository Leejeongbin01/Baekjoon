#include <iostream>
#include <queue>
using namespace std;

int g[102][102];
int map[102][102];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int N,M; 

void bfs(int x,int y)
{
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    g[x][y]=0;
    map[x][y] = 1;
    while(!q.empty()){
        int tmp1 = q.front().first;
        int tmp2 = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = tmp1+dx[i];
            int ny = tmp2+dy[i];
            if(nx>=0 && ny>=0 && nx<N && ny<M){
                if(g[nx][ny]==1){
                    q.push(make_pair(nx,ny));
                    g[nx][ny]=0;
                    map[nx][ny] = 1+map[tmp1][tmp2];
                }
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string tmp; cin >> tmp;
        for(int j=0; j<M; j++){
            g[i][j] = tmp[j]-'0';
        }
    }
    bfs(0,0);
    cout<<map[N-1][M-1] << endl;
    
    return 0;
}