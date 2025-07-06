#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int arr[1001][1001];

int main()
{
    int N; cin >> N;
    
    for(int i=1; i<=N; i++){
        int tmp1,tmp2,tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + tmp1;
        dp[i][2] = min(dp[i-1][1], dp[i-1][3]) + tmp2;
        dp[i][3] = min(dp[i-1][1], dp[i-1][2]) + tmp3;
    }

    cout << min(dp[N][1], min(dp[N][2], dp[N][3]));
    return 0;
}