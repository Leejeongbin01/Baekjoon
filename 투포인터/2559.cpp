#include <iostream>
#include <vector>
#include <algorithm>
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

    long long sum = 0;
    
    for(int i=0; i<K; i++){
        sum+=v[i];
    }
    long long mx = sum;

    
    for(int i=K; i<N; i++){
        sum += v[i]-v[i-K];

        mx = max(sum,mx);
    }

    cout << mx << "\n";
    return 0;   
}