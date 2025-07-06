#include <iostream>
using namespace std;

int arr[100001];
int dp[100001];

int main()
{
    int N; cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }

    int ans = arr[1];
    dp[1]=arr[1];
    for(int i=2; i<=N; i++){
        dp[i] = max(dp[i-1]+arr[i], arr[i]);
        if(ans < dp[i]){
            ans = dp[i];
        }
    }

    cout << ans << endl;
    return 0;
}