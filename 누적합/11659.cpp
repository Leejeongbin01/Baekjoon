#include <iostream>
using namespace std;

long long arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M; cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    while(M--){
        int a,b; cin >> a >> b;
        int ans = 0;
        ans = arr[b]-arr[a-1];
        cout << ans << "\n";
    }

    return 0;
}