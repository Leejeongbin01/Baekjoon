#include <iostream>
using namespace std;

int dp[12];

int main()
{
    int T,N;
    cin >> T;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    // dp[4] = 7;
    
    // 5
    // 1 1 1 1 1     = 1
    // 1 1 1 2 * 4   = 4
    // 1 2 2         = 3
    // 1 1 3 * 3     = 3
    // 2 3           = 1
    // 3 2           = 1
    // 5 = 13;

    while(T--){
        cin >> N;

        for(int i=4; i<=N; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout<<dp[N]<<endl;
    }

    return 0;
}