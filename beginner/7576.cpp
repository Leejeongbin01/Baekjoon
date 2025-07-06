#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M,N;
int g[1002][1002];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
bool visit[1002][1002];
queue<pair<int, int>> q;

void bfs()
{
    while(!q.empty()){
        int tmpX = q.front().first;
        int tmpY = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = tmpX + dx[i];
            int ny = tmpY + dy[i];
            if(nx>=0 && nx<M && ny>=0 && ny<N){
                if(visit[nx][ny]==false && g[nx][ny]==0){
                    q.push({nx,ny});
                    visit[nx][ny] = true;
                    g[nx][ny] = g[tmpX][tmpY]+1;
                }
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> g[i][j];
        }
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(g[i][j] == 1){
                q.push({i,j});
            }
        }
    }

    bfs();
    int cnt = -1;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(g[i][j]==0 && visit[i][j]==false){
                cout << "-1"<<endl;
                return 0;
            }
            if(cnt < g[i][j]){
                cnt = g[i][j];
            }
        }
    }

    cout << cnt - 1;
    return 0;
}