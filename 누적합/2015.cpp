#include <iostream>
#include <map>
using namespace std;

long long psum[200001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N,K; cin >> N >> K;
    for(int i=1; i<=N; i++){
        int a; cin >> a;
        psum[i]=psum[i-1]+a;
    }

    long long sum=0, ans=0;
    map<long long,int> m;
    m[0]=1;
    for(int i=1; i<=N;  i++){
        ans += m[psum[i]-K];
        m[psum[i]]++;
    }

    cout << ans << "\n";
    return 0;
}