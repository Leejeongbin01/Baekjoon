#include <iostream>
#include <vector>
using namespace std;

// 1. 간선 그래프와 각 정점의 선물값을 일단은 따로 구분하자. 
// 2. DFS를 돌릴 때, 현재 가지고 있는 선물의 갯수를 계속 체크하면서 
// 3. 다음번에 방문하는 곳의 선물 갯수만큼 없으면 방문 못하게 하자. 
// 4. 실제 DFS를 돌릴 때는 기존 선물 배열을 copy해서 쓰는게 맞을 듯. 


int N, Q;
vector<int> gift;
vector<int> g[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. input
    cin >> N;
    gift.resize(N+1, 0);
    for(int i=1; i<=N; i++){
        cin >> gift[i];
    }

    for(int i=0; i<N-1; i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cin >> Q;
    for(int i=0; i<Q; i++){
        int a,b,c; 
        cin >> a >> b >> c;

    }

    // 2. DFS
    for(int i=1; i<=N; i++){
        if(gift[i]!=0){
            DFS(i, gift[i]);
        }
    }
}