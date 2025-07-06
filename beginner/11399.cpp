#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];

int main()
{
    int N; cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);

    // 1 2 3 3 4
    // 1 3 6 9 13 -> 32
    int tmp = arr[0];
    int ans = arr[0];
    for(int i=1; i<N; i++){
        tmp = tmp + arr[i];
        ans += tmp;
    }

    cout << ans << endl;
    return 0;
}