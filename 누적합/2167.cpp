#include <iostream>
#include <cstring>
using namespace std;
int arr[301][301];
long long psum[301][301];

int main()
{
    int N,M; cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> arr[i][j];
            psum[i][j] = arr[i][j]+psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
        }
    }
    
    // for(int i=1; i<=N; i++){
    //     for(int j=1; j<=M; j++){
    //         cout << psum[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    int K; cin >> K;
    while(K--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int ans = 0;

        ans = psum[c][d] - psum[c][b-1] - psum[a-1][d] + psum[a-1][b-1];
        cout << ans << "\n";
    }
    
    return 0;
}