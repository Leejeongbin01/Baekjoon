#include <iostream>
using namespace std;

int N,M;
int arr[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. input
    cin >> N >> M;
    int prev = 1;
    for(int i=0; i<N; i++){
        int a,b; cin >> a >> b;
        for(int j=prev; j<=a+prev; j++){
            arr[j]=b;
        }
        prev += a;
    }

    // 2.check
    /*
    cout << "check\n";
    for(int i=0; i<=100; i++){
        cout << i << " : " << arr[i] << "\n";
    }
    cout <<"\n";
    */

    // 3. Cal.
    int mx = 0;
    prev = 1;
    for(int i=0; i<M; i++){
        int a,b; cin >> a >> b;
        for(int j=prev; j<a+prev; j++){
            mx = max(mx, b-arr[j]);
        }
        prev += a;
    }

    cout << mx << "\n";
    return 0;
}