#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int arr[3][101]; 
vector<int> v[101];
bool visit[101];
int ans;

void dfs(int x)
{
    if(visit[x]==true){
        return;
    }

    if(ans!=1) visit[x]=true;
    else ans=-1;

    for(int i=0; i<v[x].size();  i++){
        int tmp = v[x][i];
        if(visit[tmp]==false){
            dfs(tmp);
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
        int a; cin >> a;   
        v[i].push_back(a);
    }
    
    int cnt = 0;
    vector<int> result;
    for(int i=1; i<=N; i++){
        ans = 1;
        dfs(i);

        /*
        for(int j=1; j<=N; j++){
            cout << visit[j] << " ";
        }        
        cout << "\n";
        */

        if(visit[i]!=0){
            cnt++;
            result.push_back(i);
        }
        memset(visit, 0, sizeof(visit));
    }

    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for(int i=0; i<result.size(); i++){
        cout << result[i] << "\n";
    }
    return 0;
}