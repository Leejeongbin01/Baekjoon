#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    cin >> N >> K;
    vector<int> v;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        v.push_back(a);
    }

    
    int ans = 0;
    int mx = 0;
    vector<int> cnt(200001,0);
    int L = 0; 
    for(int i=0; i<N; i++){
        cnt[v[i]]++;

        while(cnt[v[i]]>K){
            cnt[v[L]]--;
            L++;
        }
        ans = max(ans, i-L+1);
    }

    cout << ans  << "\n";
    return 0;
}