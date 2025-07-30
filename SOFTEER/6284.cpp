#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long K,P,N;
    cin >> K >> P >> N;

    long long ans = K;
    for(int i=0; i<N; i++){
        ans *= P;
        ans %= 1000000007;
    }

    cout << ans << "\n";
    return 0;
}