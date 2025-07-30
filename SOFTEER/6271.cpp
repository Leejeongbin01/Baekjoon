#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// . = 0 -> 비어있는 칸
// * = 1 -> 소나기 (주위에 있는 지 확인하고 태범 위치 이동)
// X = 2 -> 강
// H = 3 -> 집
// W = 4 -> 세차장 (굳이인듯?)

// 1. 무조건 첫 비가 먼저 내리는 곳을 queue에 넣어주기
// 2. 그 후에 주인공 출발위치 넣어주기
// 3. 그렇게 하면 강제적으로 비가 먼저 내린 후에 주인공이 출발함. 

int R,C;
int arr[51][51];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool visitRain[51][51];
bool visit[51][51];
int ans;
queue<pair<int,pair<int,int>>> q;

void BFS()
{
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if(arr[x][y]==3 && cnt!=-1){
            ans = cnt;
            break;
        }

        if(arr[x][y]==4){
            ans = -1;
            break;
        }

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>0 && ny>0 && nx<=R && ny<=C){
                if(cnt==-1){
                    if(visitRain[nx][ny]==false && arr[nx][ny]!=2){
                        visitRain[nx][ny]=true;
                        q.push({nx,{ny,-1}});
                    }
                }
                else{
                    if(visit[nx][ny]==false && arr[nx][ny]!=2 && arr[nx][ny]!=1){
                        visit[nx][ny]=true;
                        q.push({nx,{ny,cnt+1}});
                    }
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

    // 1. input()
    cin >> R >> C;
    int startX, startY;
    int endX, endY;
    for(int i=1; i<=R; i++){
        string str; cin >> str;
        for(int j=1; j<=C; j++){
            char c = str[j-1];
            if(c=='.'){
                arr[i][j]=0;
            }
            else if(c=='*'){
                arr[i][j]=1;
                q.push({i,{j,-1}});
                visit[i][j]=true;
            }
            else if(c=='X'){
                arr[i][j]=2;
            }
            else if(c=='H'){
                arr[i][j]=3;
                endX = i; endY= j;
            }
            else if(c=='W'){
                arr[i][j]=4;
                startX = i; startY = j;
            }
            //cout << arr[i][j] << " ";  
        }
        //cout << "\n";
    }
    
    // 2. BFS()
    q.push({startX,{startY,0}});
    visit[startX][startY]=true;
    BFS();

    // 3. answer
    if(visit[endX][endY]==false){
        cout << "FAIL\n";
    }
    else{
        cout << ans << "\n";
    }

    return 0;
}