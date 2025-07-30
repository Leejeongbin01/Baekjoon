#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

// 가는 길의 최소경로 -> 다익스트라
// 제일 값이 낮은 경로로 가고 난후에 그 값의 소수를 구하면 됨. 

int N,M;
int dist[10001];
vector<pair<int,int>> v[10001];

bool isPrime(int x)
{
    if(x<=1){
        return false;
    }
    else{
        for(int i=2; i<=sqrt(x); i++){
            // 
            if(x%i==0) return  false;
        }
    }

    return true;
}

void dijkstra()
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    dist[1]=0;

    while(!pq.empty()){
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        for(int i=0; i<v[now].size(); i++){
            int next = v[now][i].first;
            int ncost = v[now][i].second;
            
            int tmp = max(ncost, cost);
            if(dist[next] > tmp){
                dist[next] = tmp;
                pq.push({tmp, next});
            }
        }
    }

    /*
    for(int i=1; i<=N; i++){
        cout << dist[i] << " ";
    }
    cout << "\n";
    */
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. input
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a,b;
        long long c;

        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    // 2. reset
    for(int i=1; i<=N; i++){
        dist[i]=1e9;
    }

    // 3. dijkstra()
    dijkstra();

    // 4. min prime number
    int ans = dist[N]+1;
    while(1){
        if(isPrime(ans)){
            break;
        }
        else{
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}