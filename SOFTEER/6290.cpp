#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[300001];
int asc[300001];
int ascmax[300001];

int main()
{
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    vector<int> dp;
    dp.push_back(arr[0]);

    for(int i=1; i<N; i++){
        int idx = lower_bound(dp.begin(), dp.end(), arr[i])-dp.begin();

        if(idx == dp.size()){ // dp 사이즈가 같다면 그냥 푸쉬 (큰 경우일때)
            dp.push_back(arr[i]);
        }
        else{
            dp[idx] = arr[i];
        }

        asc[i] = dp.size();
    }

    // 뒤에서부터 검사를 하면 감소하는 것을 알 수 있음. 
    // upper bound로 쉽게
    dp.clear();
    dp.push_back(arr[N-1]);
    for(int i=N-2; i>=0 ; i--){
        int idx = lower_bound(dp.begin(), dp.end(),arr[i]) - dp.begin();
        if(idx == dp.size()){
            dp.push_back(arr[i]);
        }
        else{
            dp[idx] = arr[i];
        }

        ascmax[i] = dp.size();
    }

    for(int i=0; i<N; i++){
        cout << asc[i] << " " << ascmax[i] << "\n";
    }

    int ans = 0;
    for(int i=0; i<N; i++){
        ans = max(ans, asc[i]+ascmax[i] -1 );
    }
    cout << ans << endl;
}