#include <iostream>
using namespace std;

int N, M;

int main()
{
    int T; cin >> T;
    while(T--){
        cin >> N >> M;

        long long ans = 1;
        int k = 1;
        for(int i=M; i>M-N; i--){
            ans *=i;
            ans /=k;
            k++;
        }

        cout << ans << endl;
    }

    return 0;
}