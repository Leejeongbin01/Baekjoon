#include <iostream>
#include <vector>
using namespace std;

int arr[10];

int main()
{
    int N; cin >> N;
    
    vector<int> v;
    while(N!=0){
        int tmp = N % 10;
        N/=10;
        arr[tmp]++;
    }

    int ans=0;
    for(int i=0; i<10; i++){
        if(i==6 || i==9)
            continue;

        if(ans <= arr[i]){
            ans = arr[i];
        }
    }

    int tmp = arr[6] + arr[9];
    if(tmp%2==1){
        tmp = tmp+1;
    }
    tmp = (tmp/2);

    cout << max(ans, tmp) << endl;

    return 0;
}