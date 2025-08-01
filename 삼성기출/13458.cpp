#include <iostream>
using namespace std;

long long N,B,C;
long long tester[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. input
    cin >> N;
    for(long long i=1; i<=N; i++){
        cin >> tester[i];
    }
    cin >> B >> C;

    // 2. cal
    long long ans = N;
    for(long long i=1; i<=N; i++){
        tester[i] -= B;
    }

    /*
    cout << "\ncheck\n";
    for(long long i=1; i<=N; i++){
        cout << tester[i] << " ";
    }
    cout << "\n\n";
    */

    for(long long i=1; i<=N; i++){
        if(tester[i]<=0) continue;

        if(tester[i]%C==0){
            ans += (tester[i]/C);
        }
        else{
            ans += (tester[i]/C) + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}