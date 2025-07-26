#include <iostream>
using namespace std;

int uft[100001];

int findf(int x)
{
    if(uft[x]==x) return x;
    return uft[x] = findf(uft[x]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M; cin >> N >> M;
    for(int i=1; i<=N; i++){
        uft[i]=i;
    }

    while(M--){
        int x,y; cin >> x >> y;
        x=findf(x);
        y=findf(y);
        uft[y]=x;
    }

    int cnt = 0;
    int cur; cin >> cur;
    cur = findf(cur);
    for(int i=1; i<N; i++){
        int x; cin >> x;
        x = findf(x);
        if(x!=cur){
            cnt++;
            cur=x;
        }
    }

    cout << cnt << "\n";
    return 0;
}