#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; 
int arr[26][26];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
bool visit[26][26];
int ans;

void dfs(int x,int y, int cnt)
{
    arr[x][y]=0;
    visit[x][y]=true;
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<=N && ny<=N && nx>0 && ny>0){
            if(arr[nx][ny]==1 && visit[nx][ny]==false){
                ans++;
                dfs(nx,ny,cnt);
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
            arr[i][j]=str[j-1]-'0';
            //cout << arr[i][j] <<" ";
        }
        //cout << "\n";
    }

    vector<int> v;    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(arr[i][j]==1){
                ans = 1;
                dfs(i,j,1);
                v.push_back(ans);
                //cout << i << " " << j << endl;
                //cout << ans << endl;
            }
        }
    }
    sort(v.begin(),v.end());
    cout << v.size() << "\n";
    for(int i=0; i<v.size(); i++){
       cout << v[i] << "\n";
    }

    return 0;
}