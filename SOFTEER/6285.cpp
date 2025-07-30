#include <iostream>
using namespace std;

int K,N;
int arr[10001][101];
int weight[10001];
int dp[10001][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. input
    cin >> K >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=K; j++){
            cin >> arr[i][j];
        }

        if(i==N){
            break;
        }

        cin >> weight[i];
    }

    // 2. dp
    for(int i=1; i<=K; i++){
        dp[1][i] = arr[1][i];
    }

    // 다음 라인을 가기전 직전의 조립 라인에 대해서 가장 최소의값을 구함. 
    // 가장 최소의 값과 weight가 작냐 VS 똑같은 라인의 값이 작냐의 싸움
    for(int i=2; i<=N; i++){
        int tmp = 1e9;
        for(int j=1; j<=K; j++){
            tmp = min(tmp, dp[i-1][j]);
        }

        for(int j=1; j<=K; j++){
            dp[i][j] = min(dp[i-1][j]+arr[i][j], tmp+arr[i][j]+weight[i-1]);
        }
    }

    // 3. answer
    int result = 1e9;
    for(int i=1; i<=K; i++){
        result = min(result,dp[N][i]);
        //cout << dp[N][i] << " ";
    }
    //cout << "\n";
    cout << result << "\n";


    return 0;
}