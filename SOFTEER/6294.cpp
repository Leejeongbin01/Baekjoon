#include <iostream>
#include <iomanip>
using namespace std;

int N,K;
int arr[1000001];

int main()
{
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }

    float sum = 0;
    while(K--){
        int a,b; cin >> a >> b;
        sum = 0;

        for(int i=a; i<=b; i++){
            sum += arr[i];
        }

        cout << fixed << setprecision(2) <<  sum / (b-a+1) << endl;
    }

    return 0;
}