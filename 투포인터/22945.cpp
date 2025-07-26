#include <iostream>
#include <vector>
using namespace std;

int arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    int start = 0;
    int end = N-1;
    int mx = 0;

    while(1){
        if((end-start)==1){
            break;
        }

        int dist = end-start-1;
        int tmp = min(arr[start], arr[end]);
        mx = max(mx, dist*tmp);

        if(arr[end]>arr[start]){
            start++;
        }
        else{
            end--;
        }
    }

    cout << mx << "\n";
    return 0;
}