#include <iostream>
using namespace std;

int dp[100001];

int main()
{
    int N;
    cin >> N;

    dp[1]=-1;
    dp[2]=1;
    dp[3]=-1;
    dp[4]=2;
    dp[5]=1;
    dp[6]=3;
    dp[7]=2;
    dp[8]=4;
    dp[9]=3;
    dp[10]=2;
    dp[11]=4;
    dp[12]=3;
    dp[13]=5;
    

    for(int i=10; i<=N; i++){
        dp[i]=min(dp[i-2]+1, dp[i-5]+1);
    }

    cout << dp[N]<<"\n";
    return 0;
}