#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S;
    cin >> N >> S;

    int arr[100001];
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    int start = 0, end = 0;
    int minLen = 1e9;
    long long total = arr[0];
    long long tmpLen = 1;
    bool flag = true;
    while((start < N && end < N)){
        if(total >= S){
            flag = false;
            minLen = min(minLen,end-start+1);
        }

        if(end+1 < N){
            if(total < S){
                end++;
                total += arr[end];
            }
            else{
                if(total - arr[start] >= S){
                    total -= arr[start];
                    start++;
                }
                else{
                    end++;
                    total += arr[end];
                }
            }
        }
        else{
            if(start < N){
                if(total-arr[start] >= S){
                    total -= arr[start];
                    start++;
                }
                else{
                    break;
                }
            }
        }

        //cout << start << " " << end << ", " << total <<  "\n";
    }
    
    if(flag){
        minLen = 0;
    }
    cout << min(minLen, end-start+1) << "\n";
    return 0;
}