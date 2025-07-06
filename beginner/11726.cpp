#include <iostream>
using namespace std;

// 1,2,3,5,8,13,21,34,55
int dp[1002];

int main()
{
    int N; cin >> N;
    dp[1]=1;
    dp[2]=2;

    for(int i=3; i<=N; i++){
        dp[i] = (dp[i-1]+dp[i-2]) % 10007;
    }

    cout<<dp[N];
    return 0;
}