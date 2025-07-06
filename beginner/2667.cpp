#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N; 
int map[26][26];
bool visit[26][26];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
vector<int> home;
int cnt=0;

void bfs(int x,int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    map[x][y]=0;
    cnt++;
    
    while(!q.empty()){
        int tmp1 = q.front().first;
        int tmp2 = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = tmp1 + dx[i];
            int ny = tmp2 + dy[i];
            if(nx>=0 && ny>=0 && nx<N && ny<N){
                if(map[nx][ny]==1){
                    q.push({nx,ny});
                    map[nx][ny] = 0;
                    cnt++;
                }
            }
        }
    }
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++){
        string tmp; cin >> tmp;
        for(int j=0; j<N; j++){
            map[i][j] = tmp[j]-'0';
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]==1){
                cnt = 0;
                bfs(i,j);
                home.push_back(cnt);
            }
        }
    }

    sort(home.begin(), home.end());
    cout << home.size() << endl;
    for(int i=0; i<home.size(); i++){
        cout << home[i] << endl;
    }

    return 0;
}