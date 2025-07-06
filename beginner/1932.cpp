#include <iostream>
using namespace std;

int arr[501][501];
long long dp[501][501];

int main()
{
    int N; cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            cin >> dp[i][j];
        }
    }

    for(int i=N-1; i>=1; i--){
        for(int j=1; j<=i; j++){
            dp[i][j] += max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    cout<<dp[1][1];

    return 0;
}