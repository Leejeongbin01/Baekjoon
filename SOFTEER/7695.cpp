#include <iostream>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1.input
    cin >> N;
    int ansX = 1e9;
    int ansY = 1e9;
    for(int i=0; i<N; i++){
        int a,b; cin >> a >> b;

        if(ansY > b){
            ansX = a;
            ansY = b;
        }
    }

    cout << ansX << " " << ansY << "\n";
    return 0;
}