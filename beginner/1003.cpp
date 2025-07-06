#include <iostream>
using namespace std;

long long arr[41] = {0,1};

long long fibo(int x)
{
    if(x==0 || x==1){
        return arr[x];
    }
    else if(arr[x]==0){
        arr[x] = fibo(x-1) + fibo(x-2);
    }
    
    return arr[x];
}

int main()
{
    // 1,1,2,3,5,8
    // 0 = 1,0,1,1,2,3
    // 1 = 0,1,1,2,3,5
    int T; cin >> T;
    while(T--){
        int N; cin >> N;

        if(N==0){
            cout << "1 0" << endl;
        }
        else{
            cout << fibo(N-1) << " " << fibo(N) << endl;
        }
    }
    
    return 0;
}