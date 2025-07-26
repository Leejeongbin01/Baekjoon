#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N,M;
int arr[101][101];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int visit[101][101];

void bfs()
{
    queue<pair<int, int>> q;
    q.push({1,1});
    visit[1][1]= -1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=1 && ny>=1 && nx<=N && ny<=M){
                if(arr[nx][ny]==1){
                    visit[nx][ny]++;
                }
                else if(arr[nx][ny]==0 && visit[nx][ny]!=-1){
                    visit[nx][ny]=-1;
                    q.push({nx,ny});
                }
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(visit[i][j]>=2){
                arr[i][j]=0;
            }
        }
    }
}

bool checkIce()
{
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(arr[i][j]==1){
                return false;
            }
            //cout << arr[i][j] << " ";
        }
        //cout << "\n";
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;    
    for(int i=1; i<=N;  i++){
        for(int j=1; j<=M; j++){
            cin >> arr[i][j];
        }
    }
    cout << "\n";

    int time=1;
    while(1){
        if(checkIce()){
            break;
        }

        time++;
        memset(visit,0,sizeof(visit));
        bfs();
    }

    cout << time << "\n";
    return 0;
}