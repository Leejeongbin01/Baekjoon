#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return b<a;
}

int main()
{
    int N; cin >> N;
    vector<int> v;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), cmp);
    //cout << "\n";

    int ans = 0;
    for(int i=0; i<N; i++){
        if((i+1)%3==0){
            continue;
        }
        else{
            ans += v[i];
        }
    }
    
    cout << ans;
    return 0;
}