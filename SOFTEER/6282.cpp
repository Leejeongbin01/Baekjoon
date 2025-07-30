#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[26][26];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool visit[26][26];
int result;
queue<pair<int, int>> q;

void dfs(int x, int y) {
    visit[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && ny >= 1 && nx <= N && ny <= N) {
            if (!visit[nx][ny] && arr[nx][ny] == 1) {
                result++;
                dfs(nx, ny);
            }
        }
    }
}


/*
int bfs(int a, int b)
{
    queue<pair<int, pair<int,int>>> q;
    visit[a][b]=true;
    q.push({a,{b,1}});
    int result = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();
        //result = max(result, cnt);

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>0 && ny>0 && nx<=N && ny<=N){
                if(visit[nx][ny]==false && arr[nx][ny]==1){
                    q.push({nx,{ny,cnt+1}});
                    visit[nx][ny]=true;
                    result++;
                }
            }
        }
    }

    return result;
}
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1.input
    cin >> N;

    for(int i=1; i<=N; i++){
        string str;
        cin >> str;
        for(int j=1; j<=N; j++){
            if(str[j-1]=='1'){
                arr[i][j]=1;
            }
        }
    }

    // 2. bfs
    vector<int> save;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(arr[i][j]==1 && visit[i][j]==false){
                //int cnt = bfs(i,j);
                visit[i][j]=true;
                result=1;
                dfs(i,j);
                save.push_back(result);
            }
        }
    }

    sort(save.begin(), save.end());
    for(int i=0; i<save.size(); i++){
        cout << save[i] << "\n";
    }


    return 0;
}