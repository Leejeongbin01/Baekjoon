#include <iostream>
#include <cmath>
using namespace std;

int N;
int dp[16];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    dp[0]=2;
    dp[1]=3;
    for(int i=2;  i<=N; i++){
        dp[i]=dp[i-1]+(pow(2,i-1));
    }

    cout << dp[N]*dp[N] << "\n";
    return 0;
}