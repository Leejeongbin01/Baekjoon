#include <iostream>
using namespace std;

int arr[100001];
int visit[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    long long ans = 0;
    int start = 0, end = 0;
    
    while(start < N){
        while(end < N && visit[arr[end]]==0){
            visit[arr[end]]=1;
            ans += (end-start+1);
            end++;
        }

        visit[arr[start]] = 0;
        start++;
    }

    cout << ans << "\n";    
    return 0;
}