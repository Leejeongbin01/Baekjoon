#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

char orgArr[101][101];
char difArr[101][101];
bool visit[101][101];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int orgAns, difAns,N;

void dfs2(int x,int y, char c)
{
    if(visit[x][y]==true){
        return;
    }

    visit[x][y]=true;
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>0 && ny>0 && nx<=N && ny<=N){
            if(visit[nx][ny]==false && difArr[nx][ny]==c){
                dfs2(nx,ny,c);
            }
        }
    }
}
void dfs(int x,int y, char c)
{
    if(visit[x][y]==true){
        return;
    }

    visit[x][y]=true;
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>0 && ny>0 && nx<=N && ny<=N){
            if(visit[nx][ny]==false && orgArr[nx][ny]==c){
                dfs(nx,ny,c);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1; i<=N; i++){
        string str; cin >> str;
        for(int j=1; j<=N; j++){
            orgArr[i][j]=str[j-1];
            difArr[i][j]=str[j-1];
            if(str[j-1]=='G'){
                difArr[i][j]='R';
            }
        }
    }

    /*
    cout << "\n";
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << orgArr[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << difArr[i][j] << " ";
        }
        cout << "\n";
    }
    */
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(visit[i][j]==false){
                orgAns++;
                dfs(i,j,orgArr[i][j]);
            }
        }
    }

    memset(visit,false,sizeof(visit));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(visit[i][j]==false){
                difAns++;
                dfs2(i,j,difArr[i][j]);
            }
        }
    }
    
    cout << orgAns << " " << difAns <<"\n";
    return 0;
}