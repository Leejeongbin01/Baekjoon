#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int>&a, pair<int,int>&b)
{
    return a.first < b.first;
}
int arr[1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N; cin >> N;
    vector<pair<int, int>> v;
    
    int max_h = -1;
    int max_idx = -1;
    for(int i=0; i<N; i++){
        int a,b; cin >> a>> b;
        arr[a]=b;
        if(max_h < b){
            max_h = b;
            max_idx = a;
        }
    }
    int ans = 0;

    int left_h = 0;
    for(int i=1; i<max_idx; i++){
        left_h = max(left_h, arr[i]);
        ans += left_h;
    }

    int right_h = 0;
    for(int i=1000; i>max_idx; i--){
        right_h = max(right_h, arr[i]);
        ans+=right_h;
    }

    cout << ans+max_h << endl;
    return 0;
}