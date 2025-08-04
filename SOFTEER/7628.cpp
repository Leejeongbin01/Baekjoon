#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 1. 연탄의 반지름의 길이의 배수인 집에서만 연탄 사용 가능
// 100이하의 소수를 구한 후에 나누어 떨어지는 지 확인하면 될듯
// 굳이 소수로 할 필욘 없음. 

int N; // 난로의 반지름 갯수
int arr[101];
vector<int> primeNum;
vector<int> v;

bool isPrime(int x)
{
    for(int i=2; i<=sqrt(x); i++){
        if(x%i==0){
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. input
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }

    // 2. cal prime number
    for(int i=2; i<=100; i++){
        if(isPrime(i)){
            primeNum.push_back(i);
        }

        v.push_back(i);
    }

    /*
    for(int i=0; i<primeNum.size(); i++){
        cout << primeNum[i] << " ";
    }
    cout << "\n";
    */

    // 3. cal max home
    int maxHome = 0;
    int tmpCnt;
    for(int i=0; i<v.size(); i++){
        tmpCnt = 0;
        for(int j=1; j<=N; j++){
            if(arr[j]%v[i] == 0){
                tmpCnt++;
            }
        }

        maxHome = max(maxHome, tmpCnt);
    }

    cout << maxHome << "\n";
    return 0;
}