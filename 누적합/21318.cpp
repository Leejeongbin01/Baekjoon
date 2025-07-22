#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    int arr[100001];
    memset(arr,0,sizeof(arr));

    int input;
    cin >> input;
    for(int i=2; i<=N; i++){
        int tmp; cin >> tmp;
        if(input > tmp){
            arr[i]=arr[i-1]+1;
        }
        else{
            arr[i]=arr[i-1];
        }
        input = tmp;
    }

    /*
    for(int i=1; i<=N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    */
    
    int Q; cin >> Q;
    while(Q--){
        int a,b; cin >> a >> b;
        int ans = 0;
        ans = arr[b]-arr[a];
        cout << ans << "\n";
    }

    return 0;
}