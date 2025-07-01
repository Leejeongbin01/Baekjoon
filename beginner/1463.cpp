#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main()
{
    int N;
    cin >> N;

    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    
    for(int i=5; i<=N; i++){
        //  18번 라인을 먼저 해줘야함. 
        // 보편적으로 이렇게 연산을 한 후에, 조건에 맞을경우 min처리해줘야함.. 
        dp[i] = dp[i-1]+1;

        if(i%2==0){
            dp[i] = min(dp[i], dp[i/2]+1);
        }

        if(i%3==0){
            dp[i] = min(dp[i], dp[i/3]+1);
        }
    }

    cout << dp[N] << endl;
    return 0;
}