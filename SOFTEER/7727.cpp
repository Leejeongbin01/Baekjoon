#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 각 나무마다 가능한 열매 수확량이 있음, 격자에

int M; // 친구들
int N;
int arr[21][21];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int visit[21][21];
vector<pair<int,int>> location;
int tmpans = 0;
vector<pair<int,int>> v;
vector<vector<pair<int,int>>> save;

void DFS(int x,int y, int cnt, int sum)
{
    if(cnt==3){
        tmpans = max(tmpans, sum);
        save.push_back(v);
        return;
    }

    visit[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>0 && ny>0 && nx<=N && ny<=N){
            if(visit[nx][ny]==false){
                //cout << cnt << " : " << nx << " " << ny << "\n";
                visit[nx][ny]=true;
                v.push_back({nx,ny});
                DFS(nx,ny,cnt+1, sum+arr[nx][ny]);
                v.pop_back();
                visit[nx][ny]=false;
            }
        }
    }
}

void seek()
{
    for(int i=0; i<save.size(); i++){
        vector<pair<int,int>> &now = save[i];
        int tmp = 0;
        for(int j=0; j<now.size(); j++){
            int x = now[j].first;
            int y = now[j].second;
            tmp += arr[x][y];
        }
        //cout << tmp << "\n";
        if(tmp==tmpans){
            for(int j=0; j<now.size(); j++){
                int x = now[j].first;
                int y = now[j].second;
                arr[x][y]=0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. input
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<M; i++){
        int a,b; cin >> a >> b;
        location.push_back({a,b});
    }

    // 2. DFS
    int ans = 0;
    for(int i=0; i<M; i++){
        int x = location[i].first;
        int y = location[i].second;
        v.push_back({x,y});
        DFS(x,y,0, arr[x][y]);
        seek();
        //cout << tmpans << "\n";
        ans += tmpans;
        tmpans = 0;
        memset(visit, 0 ,sizeof(visit));
        v.clear();
        save.clear();
    }

    /*
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    */
    cout << ans << "\n";
    return 0;
}