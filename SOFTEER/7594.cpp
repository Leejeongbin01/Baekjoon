#include <iostream>
using namespace std;

int N;
int arr[5][5];
bool visit[5][5];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int tempCnt;
int ans;

void dfs(int cnt,int tmp)
{
    if(cnt == tempCnt){ // 4개까지 확인 후 리턴
        ans = max(ans, tmp);
        return;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visit[i][j]==0){
                visit[i][j]=1;

                for(int k=0; k<4; k++){ // 동서남북 확인
                    int nx = i+dx[k];
                    int ny = j+dy[k];

                    if(nx>=0 && ny>=0 && nx<N && ny<N){
                        if(visit[nx][ny]==0){
                            visit[nx][ny]=1;
                            dfs(cnt+1, tmp+arr[i][j]+arr[nx][ny]); 
                            visit[nx][ny]=0;
                        }
                    }
                }
                visit[i][j]=0;
            }
        }
    }
}


int main()
{
    cin >> N;
    if(N==2){
        tempCnt = 2;
    }
    else{
        tempCnt = 4;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    dfs(0,0);
    cout << ans << "\n";
    return 0;
}