#include <iostream>
using namespace std;

int N,K;
int arr[101][101]; // N, K
int weight[101][101][101]; // N,K,0~101까지의 weight
int dp[101][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1.input
    cin >> K >> N;
    for(int i=0; i<N-1; i++){
        for(int j=0; j<K; j++){
            cin >> arr[i+1][j+1];
        }

        for(int j=0; j<K; j++){
            for(int k=0; k<K; k++){
                if(j!=k){
                    cin >> weight[i+1][j+1][k+1];
                }
            }
        }
    }

    for(int i=0; i<K; i++)
        cin >> arr[N][i+1];
        
    // 2.check
    /*
    cout << "\n";
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << "\n";
    cout << weight[1][1][1] << " " << weight[1][1][2] << " " << weight[1][1][3] << "\n";
    cout << weight[1][2][1] << " " << weight[1][2][2] << " " << weight[1][2][3] << "\n";
    cout << weight[1][3][1] << " " << weight[1][3][2] << " " << weight[1][3][3] << "\n";
    
    cout << "\n";
    cout << weight[2][1][1] << " " << weight[2][1][2] << " " << weight[2][1][3] << "\n";
    cout << weight[2][2][1] << " " << weight[2][2][2] << " " << weight[2][2][3] << "\n";
    cout << weight[2][3][1] << " " << weight[2][3][2] << " " << weight[2][3][3] << "\n";
    */

    for(int i=1; i<=N; i++){
        dp[1][i] = arr[1][i];
    }
    
    for(int i=2; i<=N; i++){
        for(int k=1; k<=K; k++){
            int tmp = 1e9;
            for(int j=1; j<=K; j++){
                int mt = (j==k) ? 0 : weight[i-1][j][k];
                tmp = min(tmp, dp[i-1][j]+mt);
            }
            dp[i][k] = arr[i][k] + tmp;
        }
    }

    int result = 1e9;
    for(int i=1; i<=K; i++){
        result = min(result, dp[N][i]);
    }

    cout << result << "\n";
    return 0;
}