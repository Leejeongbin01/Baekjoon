#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N,M,Q;
int arr[129][129];
queue<pair<int,int>> q;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
bool visit[129][129];

void bfs(int org, int chg)
{
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>0 && ny>0 && nx<=N && ny<=M){
                if(visit[nx][ny]==false && arr[nx][ny]==org){
                    visit[nx][ny]=true;
                    arr[nx][ny]=chg;
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

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> arr[i][j];
        }
    }
    cin >> Q;
    
    while(Q--){
        int a,b,c;
        cin >> a >> b >> c;
        memset(visit,0,sizeof(visit));

        q.push({a,b});
        visit[a][b]=true;
        bfs(arr[a][b],c);
        arr[a][b]=c;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}