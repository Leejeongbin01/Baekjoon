#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
vector<vector<int>> arr;
queue<pair<int,int>> NQ;
queue<pair<int,int>> GQ;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool Nvisit[1001][1001];
bool Gvisit[1001][1001];


void BFS()
{
    bool flag = false;
    while(!NQ.empty()){
        /*
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        */
        int nqSize = NQ.size();
        while(nqSize--){
            int x = NQ.front().first;
            int y = NQ.front().second;
            NQ.pop();

            if(arr[x][y]==3){
                flag = true;
            }

            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>0 && ny>0 && nx<=N && ny<=M){
                    if(Nvisit[nx][ny]==false && arr[nx][ny]!=1 && arr[nx][ny]!=2){
                        Nvisit[nx][ny]=true;
                        NQ.push({nx,ny});
                        //arr[nx][ny]=4;
                    }
                }
            }
        }

        int gqSize = GQ.size();
        while(gqSize--){
            int x = GQ.front().first;
            int y = GQ.front().second;
            GQ.pop();

            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>0 && ny>0 && nx<=N && ny<=M){
                    if(Gvisit[nx][ny]==false){
                        Gvisit[nx][ny]=true;
                        GQ.push({nx,ny});
                        if(arr[nx][ny]==1) continue;
                        arr[nx][ny]=2;

                        
                    }
                }
            }
        }
    }

    if(flag){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}

int main()
{
    // 1. input
    cin >> N >> M;
    arr.resize(N+1, vector<int>(M+1,0));
    for(int i=1; i<=N; i++){
        string str; cin >> str;
        for(int j=1; j<=M; j++){
            if(str[j-1]=='.'){
                arr[i][j] = 0;
            }
            else if(str[j-1]=='#'){
                arr[i][j] = 1;
            }
            else if(str[j-1]=='G'){
                arr[i][j] = 2;
                GQ.push({i,j});
            }
            else if(str[j-1]=='D'){
                arr[i][j] = 3;
            }
            else if(str[j-1]=='N'){
                arr[i][j] = 4;
                NQ.push({i,j});
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    // 2 BFS()
    BFS();

    return 0;
}