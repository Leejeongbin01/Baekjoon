#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[100001];
int leftArr[100001];
int rightArr[100001];

void Cal()
{
    leftArr[1] = arr[1];
    int tmp = arr[1];
    for(int i=2; i<=N; i++){
        tmp = max(arr[i], tmp+arr[i]);
        leftArr[i] = max(leftArr[i-1], tmp);
    }

    rightArr[N] = arr[N];
    tmp = arr[N];
    for(int i=N-1; i>=0; i--){
        tmp = max(arr[i], tmp+arr[i]);
        rightArr[i] = max(rightArr[i+1], tmp);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. input
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }

    // 2. cal
    Cal();

    // 3. check
    
    for(int i=1; i<=N; i++){
        cout << leftArr[i] << " " << rightArr[i] << "\n";
    }
    
    
    // answer
    int ans = -1e9;
    for(int i=1; i<=N-2; i++){
        for(int j=i+2; j<=N; j++){
            ans = max(ans, leftArr[i]+rightArr[j]);
        }
    }
    cout << ans << "\n";
    return 0;
}