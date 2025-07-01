#include <iostream>
using namespace std;

int dp[5000];

int main()
{
    // 3,5 중 나눠서 제일 적은 봉다리로..  
    int N;
    cin >> N;
    
    dp[3] = 1;
    dp[5] = 1;

    for(int i=6; i<=N; i++){
        if(dp[i-3]){
            dp[i] = dp[i-3] + 1;
        }

        if(dp[i-5]){
            dp[i] = dp[i-5] + 1;
        }
    }

    if(!dp[N]) dp[N] = -1;
    cout<< dp[N] << endl;
    return 0;
}