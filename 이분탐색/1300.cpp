#include <iostream>
using namespace std;

long long N,K;

long long arrCnt(long long x)
{
    long long ret = 0;
    for(long long i=1; i<=N; i++){
        ret += min(N, x/i);
        //cout << ret << "\n";
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    //cout <<"\n";

    //cout << arrCnt(6) << "\n";

    // L과 R사이에 무조건 arr[K]에 해당하는 값이 있을거임. 
    // 찾기 위해선 이분탐색을 하는것이 좋다. 
    // 그러면 어떤 값을 기준으로 해야하나 -> mid를 구하고 mid에 해당하는 value의 수를 구해줘야함
    // 구한 것이 K보다 작으면 L를 올려주고 반대이면 R을 내려주고
    long long L = 1, R = K;
    while(L!=R){
        long long M = (L+R)/2;
        long long res = arrCnt(M);
        if(res < K){
            L=M+1;
        }
        else{
            R=M;
        }

        //cout << "(" << L << ", " << R << ", " << M;
        //cout << ") res : " << res << "\n";
    }

    cout << L << "\n";
    return 0;
}