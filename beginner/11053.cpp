#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];

int main()
{
    int N; cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }

    int sum = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(arr[j]+1, arr[i]);
            }
        }
        sum = max(sum, dp[i]);
    }
    return 0;
}