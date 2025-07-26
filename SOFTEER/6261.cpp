#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N,T;
    cin >> N >> T;

    /*
    while(T--){
        vector<long long> c(N+1), d(N+1,0);

        for(int i=1; i<=N; i++){
            cin >> c[i];
            if(i<N) cin >> d[i];
        }

        long long prefC = 0, prefD = 0;
        long long ans = 1e9;

        for(int i=1; i<=N; i++){
            prefC += c[i];
            if(i<N) prefD += d[i];
            ans = min(ans, (prefC+prefD)/i);
            //cout << ans << "\n";
        }

        cout << ans << "\n";
    }
    */
    
    return 0;
}