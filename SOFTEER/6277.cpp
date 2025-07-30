#include <iostream>
#include <vector>
using namespace std;

int N,K;
bool visit[2001][2001];
vector<pair<int,int>> v[21];
int minAns = 1e9;
vector<pair<int,int>> save;

void dfs(int x, int y, int ch)
{
    if(ch == K){
        int minX = 1e9;
        int minY = 1e9;
        int maxX = -1e9;
        int maxY = -1e9;
        
        /*
        cout << "save\n";
        for(int i=0; i<save.size(); i++){
            cout << save[i].first << " " << save[i].second <<"\n";
        }
        */
        
        for(int i=0; i<K; i++){
            int a = save[i].first;
            int b = save[i].second;

            minX = min(minX, a);
            minY = min(minY, b);
            maxX = max(maxX, a);
            maxY = max(maxY, b);
        }

        //cout << minX << " " << minY << ", " << maxX <<" "<<maxY<<"\n";
        minAns = min(minAns, ((maxX-minX)*(maxY-minY)));
        return;
    }

    visit[1000+x][1000+y]=true;
    for(int i=ch+1; i<=K; i++){
        for(int j=0; j<v[i].size(); j++){
            int a = v[i][j].first;
            int b = v[i][j].second;
            save.push_back({a,b});
            dfs(a,b,ch+1);
            save.pop_back();
        }
    }
}   

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. input
    cin >> N >> K;
    for(int i=0; i<N; i++){
        int x,y,c;
        cin >> x >> y >> c;
        v[c].push_back({x,y});
    }

    // 2. check
    /*
    cout << "\n";
    for(int i=1; i<=K; i++){
        for(int j=0; j<v[i].size(); j++){
            cout << v[i][j].first << " " << v[i][j].second <<"\n";
        }
    }
    cout << "\n";
    */

    // 3. back tracking
    for(int i=0; i<v[1].size(); i++){
        save.push_back({v[1][i].first,v[1][i].second});
        dfs(v[1][i].first, v[1][i].second, 1);
        save.pop_back();
    }

    cout << minAns << "\n";
    return 0;
}