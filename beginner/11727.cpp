#include <iostream>
using namespace std;

int dp[1001];

int main()
{
    int N; cin >> N;
    dp[1]=1;
    dp[2]=3;
    dp[3]=5;
    // 4-> 11
    // 5-> 21
    // 6-> 43
    // 7-> 85
    // 8-> 171

    for(int i=4; i<=N; i++){
        dp[i] = (dp[i-1] + dp[i-2]*2)%10007;
    }
    cout<<dp[N]<<endl;
    return 0;
}