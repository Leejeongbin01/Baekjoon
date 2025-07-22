#include <iostream>
#include <cstring>
using namespace std;

long long arr[201][201];
int N,M; 

long long func(int x,int y)
{
    long long result = -9e8;
    for(int i=1; i<=N-x+1; i++){
        for(int j=1; j<=M-y+1; j++){
            result = max(result, arr[i+x-1][j+y-1]-arr[i-1][j+y-1]-arr[i+x-1][j-1]+arr[i-1][j-1]);
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    long long ans = -9e8;
    int x=-1, y=-1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            int a; cin >> a;
            arr[i][j] = a + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }

    // for(int i=0; i<=N; i++){
    //     for(int j=0; j<=M; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            ans = max(ans,func(i,j));
        }
    }    
    cout << ans <<"\n";
    return 0;
}