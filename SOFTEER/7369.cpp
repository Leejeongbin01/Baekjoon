#include <iostream>
using namespace std;

int N;
pair<int,int> arr[1002][1002];
pair<int,int> dp[1002][1002];
int ans;

void setup()
{
    dp[1][1].first = arr[1][1].first;
    dp[1][1].second = arr[1][1].second;

    for(int i=2; i<=N; i++){
        dp[1][i].first = dp[1][i-1].first + arr[1][i].first;
        dp[1][i].second = max(dp[1][i-1].second, arr[1][i].second);
    }

    for(int i=2; i<=N; i++){
        dp[i][1].first = dp[i-1][1].first + arr[i][1].first;
        dp[i][1].second = max(dp[i-1][1].second, arr[i][1].second);
    }

    /*
    for(int i=1;i<=N;i++){
        for(int j=1; j<=N; j++){
            cout << dp[i][j].first << " " << dp[i][j].second << "\n";
        }
    }
    */
}

void cal()
{
    for(int i=2; i<=N; i++){
        for(int j=2; j<=N; j++){
            if(i==N && j==N){
                dp[i][j].first = max(dp[i-1][j].first + dp[i-1][j].second, dp[i][j-1].first + dp[i][j-1].second) + arr[i][j].first;
            }
            else{
                if(dp[i-1][j].first > dp[i][j-1].first){
                    dp[i][j].first = dp[i-1][j].first + arr[i][j].first;
                    dp[i][j].second = max(dp[i][j].second, dp[i-1][j].second);
                }
                else if(dp[i-1][j].first < dp[i][j-1].first){
                    dp[i][j].first = dp[i][j-1].first + arr[i][j].first;
                    dp[i][j].second = max(dp[i][j].second, dp[i][j-1].second);
                }
                else{
                    dp[i][j].first = dp[i][j-1].first + arr[i][j].first;
                    dp[i][j].second = max(max(dp[i-1][j].second, dp[i][j-1].second),arr[i][j].second);
                }
            }
        }
    }

    /*
    for(int i=1;i<=N;i++){
        for(int j=1; j<=N; j++){
            cout << dp[i][j].first << " " << dp[i][j].second << "\n";
        }
    }
    */
}

int main()
{
    // 1.input
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int a; cin >> a;
            arr[i][j].first = a;
            arr[i][j].second = a;
        }
    }

    // 2. setup
    setup();

    // 3. cal
    cal();

    cout << dp[N][N].first << "\n";
    return 0;
}