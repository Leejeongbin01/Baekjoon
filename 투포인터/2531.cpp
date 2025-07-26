#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N,D,K,C;
int arr[60000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> D >> K >> C;
    
    for(int i=0; i<N; i++){
        int a; cin >> a;
        arr[i]=a;
        arr[i+N]=a;
    }

    vector<int> cnt(D+1,0);
    int kind = 0;

    for(int i=0; i<K; i++){
        if(cnt[arr[i]]==0) kind++;
        cnt[arr[i]]++;
    }

    int ans = kind + (cnt[C]==0 ? 1:0);
    for(int i=1; i<N; i++){
        cnt[arr[i-1]]--;
        if(cnt[arr[i-1]]==0) kind--;

        if(cnt[arr[i+K-1]]==0)kind++;
        cnt[arr[i+K-1]]++;

        ans = max(ans, kind+(cnt[C]==0?1:0));
    }

    cout << ans << "\n";
    return 0;
}