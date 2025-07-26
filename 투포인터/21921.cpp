#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,X;
    cin >> N >> X;
    int arr[250001];
    //int sum[250001];

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    int sum = 0;
    for(int i=0; i<X; i++){
        sum += arr[i];
    }

    int cnt = 1;
    int mx = sum;
    for(int i=X; i<N; i++){
        sum += arr[i]-arr[i-X];

        if(sum > mx){
            mx = sum;
            cnt = 1;
        }
        else if(sum==mx){
            cnt++;
        }
    }

    if(mx==0) cout <<"SAD\n";
    else {
        cout << mx << "\n" << cnt << "\n";
    }
    return 0;
}