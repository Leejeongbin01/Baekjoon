#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<int> service(N+1, 0);
        for(int i=1; i<=N; i++){
            cin >> service[i];
        }
        sort(service.begin(), service.end());
        int ans = 0;
        
        int start = 1; 
        int end = N;
        int curSize = 0;
        while(1){
            cout << "before : " << start <<", " << end << "   ";
            curSize = service[start]+service[end];
            if(start+1<end){
                if(curSize+service[start+1] <= 900){
                    ans++;
                    end--;
                    start +=2;
                }
                else{
                    ans++;
                    end--;
                    start += 1;
                }
            }
            else if(start==end){
                ans++;
                break;
            }
            else if((start + 1) == end){
                if(curSize <= 900){
                    ans++;
                }
                else{
                    ans += 2;
                }
                break;
            }
            else{
                break;
            }
            cout << "after : " << start <<", " << end <<"\n";
        }
        
        cout << ans << "\n";
    }

    return 0;
}