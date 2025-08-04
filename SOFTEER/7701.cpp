#include <iostream>
#include <vector>
#include <queue>
#include <stack> 
using namespace std;



const int MAX_N = 200001;
int N,M,K;
vector<int> g[MAX_N];
queue<int> toDelete; // 초기 삭제 정점(T=1)
stack<vector<pair<int,int>>> edgeStack; // 각 시간에 삭제된 간선들(역순)
bool erased[MAX_N];
int parent[MAX_N];

int Find(int x)
{
    if(x==parent[x]){
        return x;
    }
    
    return parent[x] = Find(parent[x]);
}

bool Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a==b) return false;
    parent[b] = a;
    return true;
}

bool hasCycle(const vector<pair<int,int>> &edges)
{
    for(auto [u,v] : edges){
        if(!Union(u,v)) return true; // 사이클
    }

    return false;
}

void bfs(int n)
{
    while(n){
        int size = toDelete.size();
        edgeStack.push(vector<pair<int,int>>());
        vector<pair<int,int>> &now = edgeStack.top();

        while(size--){
            int curr = toDelete.front(); toDelete.pop();
            if (erased[curr]) continue;  //
            erased[curr] = true;
            n--;

            for(int next : g[curr]){
                if(erased[next]) continue;
                now.push_back({curr, next}); // 접근 안한것들은ㅇ 넣어주기
                // 현재 값과 그 다음값을 now에 저장함. 
                toDelete.push(next);
            }
        }
    }
}


int solve()
{
    bfs(N); // 역순으로 먼저 시간에 맞게 넣어줌. 
    for(int i=1; i<=N; i++){
        parent[i] = i;
    }

    // 중복 간선을 없애기 위함.. 
    while(!edgeStack.empty()){
        vector<pair<int,int>>& topEdges = edgeStack.top();
        if(topEdges.empty()){
            edgeStack.pop();
        }
        else{
            break;
        }
    }

    int t = edgeStack.size();
    while(!edgeStack.empty()){
        t--;
        if(hasCycle(edgeStack.top())) break;
        edgeStack.pop();
    }

    return t+1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. input
    cin >> N >> M >> K;
    for(int i=0; i<M; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=0; i<K; i++){
        int x; cin >> x;
        toDelete.push(x);
    }

    cout << solve() << "\n";
    return 0;
}
