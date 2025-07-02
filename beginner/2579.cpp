#include <iostream>
using namespace std;

int dp[301];

int main()
{
    int N;
    cin >> N;

    int tmp[301];
    for(int i=0; i<N; i++){
        cin >> tmp[i+1];
    }

    dp[1] = tmp[1];
    dp[2] = tmp[1] + tmp[2];
    dp[3] = max(tmp[1]+tmp[3], tmp[2]+tmp[3]);

    for(int i=4; i<=N; i++){
        dp[i]=max(dp[i-2]+tmp[i], dp[i-3]+tmp[i-1]+tmp[i]);
    }

    cout<<dp[N]<<endl;
    return 0;
}