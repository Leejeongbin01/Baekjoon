#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

/*
   t = 0,1,2, 3
(1,1): 2 6 12 9
(1,2): 7 1 11 6
(1,3): 6 3 5 11

(2,1): 1 1 12 9
(2,2): 3 11 8 2
(2,3): 1 7 11 9

(3,1): 4 6 2 3
(3,2): 2 4 2 4
(3,3): 6 9 2 6
*/

int N, T;
int arr[101][101][4];
set<pair<int, int>> ans;
bool visit[101][101][4][4]; // 시간과 방향에 따라 방문횟수를 cnt해야함. 
// 방향이 달라도 달리 방문한 것임.

int dy[4] = {0, -1, 0, 1}; // 동 북 서 남
int dx[4] = {1, 0, -1, 0};

vector<int> signals[13] = {
    {},
    {0,1,3}, {1,0,2}, {2,1,3}, {3,0,2},
    {0,1}, {1,2}, {2,3}, {3,0},
    {0,3}, {1,0}, {2,1}, {3,2}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> T;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=0; k<4; k++){
                int a; cin >> a;
                arr[i][j][k]=a;
            }
        }
    }

    queue<pair<int,pair<int,int>>> q;
    q.push({1,{1,1}}); // 바라보는 방향이 북쪽임. 
    visit[1][1][0][1] = 1;
    ans.insert({1,1});
    int t = 0;

    while(!q.empty()){
        int size = q.size();
        if(t==T) break;
        while(size--){
            int x = q.front().first;
            int y = q.front().second.first;
            int dir = q.front().second.second;
            q.pop();

            int signal = arr[x][y][t%4];
            if(signals[signal][0] != dir) continue; 
            // 바라보는 방향과 직진이어야함. 
            // 즉, 최소한 해당 점을 통과는 할 수 있어야함. 

            for(int i : signals[signal]){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>0  && ny>0 && nx<=N && ny<=N){
                    if(visit[nx][ny][t%4][i]==false){
                        visit[nx][ny][t%4][i]=true;
                        q.push({nx,{ny,i}});
                        ans.insert({nx,ny});
                    }
                }
            }
        }
        t++;
    }

    cout << ans.size() << "\n";
    return 0;
}