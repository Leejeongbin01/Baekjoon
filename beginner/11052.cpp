#include <iostream>
using namespace std;

int dp[1001];
int arr[1001];

int main()
{
    int N; cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i], dp[i-j] + arr[j]);
        }
    }

    cout << dp[N] << endl;
    return 0;
}