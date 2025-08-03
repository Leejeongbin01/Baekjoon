#include <iostream>
using namespace std;

int arr[1002];

int main()
{
    int N; cin >> N;
    int minD = 1e9;

    // 1. input
    int prev; cin >> prev;
    arr[1] = prev;
    for(int i=2;  i<=N; i++){
        int  a; cin >> a;
        arr[i] = a;

        minD = min(minD, a-prev);
        prev = a;
    }

    // 2. check
    //cout << minD << "\n";

    // 3. cal
    int result = 0;
    for(int i=2; i<=N; i++){
        if(arr[i]-arr[i-1]==minD) result++;
    }

    cout << result << "\n";
    return 0;
}