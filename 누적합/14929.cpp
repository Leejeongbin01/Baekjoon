#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    int arr[100001];
    memset(arr,0,sizeof(arr));
    long long total = 0;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        total += arr[i];
    }

    // 전체 합은 2
    // a[0]=1, a[1]=-2, a[2]=3
    // 1. 전체합 - a[0] = 2-1=1
    // 1. a[0] * 1 = 1
    // 1. 누적합 = 1

    // 2. 전체합 - a[1] = 1--2=3
    // 2. a[1] * 3 = -6
    // 2. 누적합 = -5

    // 3. 전체합 - a[2] = 3 - 3 = 0
    // 3. a[2] * 0 = 0
    // 3. 누적합 = -5

    // 전체식은 a[0]*(뒷) + a[1]*(뒷)... 
    // 뒷부분은 전체 합
    
    long long sum = 0;
    for(int i=0; i<N; i++){
        long long tmp = total - arr[i]; 
        tmp = tmp * arr[i];
        sum += tmp;
        total -= arr[i];
    }

    cout << sum << "\n";
    return 0;
}