#include <iostream>
using namespace std;

long long arr[1025][1025];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M; cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int a; cin >> a;
            arr[i][j] = a + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }

    /*
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    */

    while(M--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int ans = 0;
        ans = arr[c][d]-arr[c][b-1]-arr[a-1][d]+arr[a-1][b-1];
        cout << ans << "\n";
    }
    return 0;
}