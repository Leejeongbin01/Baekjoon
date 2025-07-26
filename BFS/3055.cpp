#include <iostream>
#include <queue>
using namespace std;

int R,C;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
bool visit[51][51];
bool water_visit[51][51];
int arr[51][51];
queue<pair<int, pair<int,int>>> q;

// q를 2개 사용하여, 해당 q의 사이즈만큼만 돌리는 것이 베스트임. 
// 

int bfs()
{
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second.first;
        int cnt = q.front().second.second;
        if(arr[x][y]==3){
            //cout << "done!\n";
            return cnt;
        }
        q.pop();

        // cout << "x,y : "  << x <<  " "  << y << endl;
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>0 && ny>0 && nx<=R && ny<=C){
                if(arr[nx][ny]==-1) continue;
                //cout << "nx,ny : " << nx << " " << ny << " ," << cnt << "\n"; 

                if(cnt == -1 && water_visit[nx][ny]==false && arr[nx][ny]!=3){ // 물
                    arr[nx][ny] = 1;
                    water_visit[nx][ny]=true;
                    q.push({nx,{ny,-1}});
                    //cout << "water : " << nx << " " << ny << "\n";
                }
                else if(cnt != -1){ // 고슴도치
                    if(visit[nx][ny]==false && arr[nx][ny]==0 || arr[nx][ny]==3){
                        bool water_check = false;
                        for(int j=0; j<4; j++){
                            int tmpx = nx+dx[j];
                            int tmpy = ny+dy[j];
                            if(water_visit[tmpx][tmpy]==false){
                                water_check=true;
                            }
                        }

                        if(water_check==true){
                            visit[nx][ny]=true;
                            q.push({nx,{ny,cnt+1}});
                            //cout << "S : " << nx << " " << ny << "\n";
                        }
                    }
                }
            }
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for(int i=1; i<=R ; i++){
        string str; cin >> str;
        for(int j=1; j<=C; j++){
            if(str[j-1]=='.'){ // 움직여도 됨.
                arr[i][j]=0;
            }
            else if(str[j-1]=='*'){ // 물샛기
                arr[i][j]=1;
                //q.push({i,{j,-1}}); // 물은 굳이ㅇ cnt를 셀 필요없는듯
                water_visit[i][j]=true;
            }
            else if(str[j-1]=='X'){ // 돌
                arr[i][j]=-1;
            }
            else if(str[j-1]=='S'){ // 고슴도치샛기
                arr[i][j]=2;
                visit[i][j]=true;
                //q.push({i,{j,1}});
            }
            else if(str[j-1]=='D'){ // 비버 굴
                arr[i][j]=3;
            }
        }
    }


    bool check = false;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            
            if(arr[i][j]==2){
                for(int k=0; k<4; k++){
                    int tmpx = i+dx[k];
                    int tmpy = j+dy[k];
                    if(arr[tmpx][tmpy]==1) check=true;
                }
            }
            //cout << arr[i][j] << " ";
        }
        //cout << "\n";
    }
    
    if(check){
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if(arr[i][j]==2){
                    q.push({i,{j,1}});
                }
            }
        }
        
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if(arr[i][j]==1){
                    q.push({i,{j,-1}});
                }
            }
        }
    }
    else{
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if(arr[i][j]==1){
                    q.push({i,{j,-1}});
                }
            }
        }
        
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if(arr[i][j]==2){
                    q.push({i,{j,1}});
                }
            }
        }
    }
    
    int ans = bfs()-1;
    if(ans==-1){
        cout << "KAKTUS\n";
    }
    else{
        cout << ans << "\n";
    }
    return 0;
}