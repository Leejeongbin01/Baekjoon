#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

vector<pair<int, int>> v[20001];
int dist[20001];
int N,M,K;

void Dijkstra()
{
    priority_queue<pair<int,int>> pq;
    pq.push({0,K});
    dist[K]=0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i].first;
            int ncost = v[cur][i].second;

            if(dist[next]>cost+ncost){
                dist[next]=cost+ncost;
                pq.push({-dist[next],next});
            }
        }
    }

    for(int i=1; i<=N; i++){
        if(dist[i]==INF){
            cout <<"INF\n";
        }
        else{
            cout << dist[i] << "\n";
        }
    }
}

int main()
{
    // 1. input
    cin >> N >> M;
    cin >> K;
    for(int i=0; i<M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }

    for(int i=1; i<=N; i++){
        dist[i]=INF;
    }
    
    Dijkstra();
    return 0;
}