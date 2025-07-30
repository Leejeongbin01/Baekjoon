#include <iostream>
using namespace std;

int N;
int A[1001];
int AtoB[1001];
int B[1001];
int BtoA[1001];
int dp[1001][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. input
    cin >> N;
    for(int i=1; i<N; i++){
        cin >> A[i] >> B[i] >> AtoB[i] >> BtoA[i];
    }
    cin >> A[N] >> B[N];

    // a작업장 -> 0
    // b작업장 -> 1
    dp[1][1]=A[1];
    dp[1][2]=B[1];

    for(int i=2; i<=N; i++){
        dp[i][1] = A[i] + min(dp[i-1][1],dp[i-1][2]+BtoA[i-1]);
        dp[i][2] = B[i] + min(dp[i-1][2],dp[i-1][1]+AtoB[i-1]);
    }

    cout << min(dp[N][1],dp[N][2]) << "\n";
    return 0;
}