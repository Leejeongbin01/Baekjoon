#include <iostream>
#include <cstring>
using namespace std;


int N,M,P;
int visit[100001];
int v[100001];
int r[100001];

int dfs(int x){
    visit[x]=1;
    if(v[x]==-1){
        return 0; // 그냥 끝
    }

    int cur = r[v[x]];
    int result = 0;
    if(!visit[cur]){
        int val = dfs(cur);
        if(val==-1) return -1;
        else result += val;
    }
    else{
        return -1;
    }

    return result+1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(v,-1,sizeof(v));
    cin >> N >> M >> P;

    // 채널 b를 틀면 -> v[b]번쨰 노인이 r[v[b]]를 싫어해서 다시 b로 바꾼다. 
    for(int i=0; i<N; i++){
        int a,b;
        cin >> a >> b;
        r[i]=a;
        if(v[b] == -1) v[b]=i;
    }
    // r[0]=1, 
    // r[1]=2, 
    // r[2]=3,
    // v[2]=0, v[3]=1

    cout << dfs(P) << "\n";
    return 0;
}