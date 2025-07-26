#include <iostream>
#include <vector>
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

    int start = 0;
    int end = 0;
    int oddCount = ((v[0]%2==0) ? 0:1); 
    int evenCount = ((v[0]%2==0) ? 1:0); 
    int ans = 0;

    while(start < N  && end <N){
        ans = max(ans, evenCount);
        
        if(end+1 < N){
            if(oddCount + (v[end+1]%2) <= K){
                end++;
                if(v[end]%2==0){
                    evenCount++;
                }
                else{
                    oddCount++;
                }
            }
            else{
                if(v[start]%2==0){
                    evenCount--;
                }
                else{
                    oddCount--;
                }
                start++;
            }
        }
        else{
            break;
        }
    }
    
    cout << ans << "\n";
    return 0;
}