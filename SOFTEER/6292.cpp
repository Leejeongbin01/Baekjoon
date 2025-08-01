#include <iostream>
using namespace std;

#define MOD 1000000007
long long K,P,N;
// K는 바이러스 갯수
// P는 몇배씩
// N은 시간(씩.1초씩)

long long calc(long long exp)
{
    if(exp == 1){
        return P;
    }

    long long half = calc(exp/2); // 절반 계산하고
    long long result = (half*half) % MOD; // 나머지 절반도 계산하고
    if(exp%2==1){
        result = (result * P) % MOD;
    }

    return result;
}

int main()
{
    cin >> K >> P >> N;
    long long power = calc(N*10); // 시간 단위를 1분으로 
    cout << (K*power) % MOD << endl;
    return 0;
}