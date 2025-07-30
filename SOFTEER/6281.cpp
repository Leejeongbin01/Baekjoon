#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N,M;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int arr[101][101];
bool visit[101][101];

void melt()
{
    queue<pair<int,int>> q;
    q.push({0,0});
    visit[0][0]=true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && ny>=0 && nx<=N && ny<=M){
                if(visit[nx][ny]==false && arr[nx][ny]==0){
                    q.push({nx,ny});
                    visit[nx][ny]=true;
                }
            }
        }
    }

    queue<pair<int,int>> tmp;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(arr[i][j]==1){
                int flag = 0;
                for(int k=0; k<4; k++){
                    if(visit[i+dx[k]][j+dy[k]]==true){
                        flag++;
                    }
                }
                if(flag >= 2){
                    tmp.push({i,j});
                }
            }
        }
    }

    while(!tmp.empty()){
        int x = tmp.front().first;
        int y = tmp.front().second;
        tmp.pop();

        arr[x][y]=0;
    }
}

bool isIce()
{
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(arr[i][j]==1){
                return false;
            }
        }
    }

    return true;
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

    int time=0;
    while(1){
        if(isIce()){
            break;
        }

        /*
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        */

        time++;
        memset(visit,false,sizeof(visit));
        melt();
    }

    cout << time << "\n";
    return 0;
}