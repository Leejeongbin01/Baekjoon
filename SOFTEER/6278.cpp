#include <iostream>
using namespace std;

int P, N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. input
    cin >> P >> N;
    long long tmp, ans=0;
    cin >> tmp;
    
    ans += tmp;
    for(int i=1; i<N; i++){
        long long a; cin >> a;
        ans = ans * P + a;
    }

    cout << (ans) % 1000000007 << "\n";
    return 0;
}