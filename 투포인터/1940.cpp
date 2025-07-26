#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N;
    cin >> M;
    vector<int> v;

    for(int i=0; i<N; i++){
        int a; cin >> a;
        v.push_back(a);    
    }

    sort(v.begin(), v.end());

    int start=0;
    int end=1;
    int ans = 0;
    while(start!=(N-1)){
        if(v[start]+v[end]==M) ans++;

        if(end==N-1){
            start++;
            end = start+1;
        }
        else{
            end++;
        }
    }

    cout << ans << "\n";
    return 0;
}