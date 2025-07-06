#include <iostream>
#include <algorithm>
using namespace std;

int a[51];
int b[51];

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int N; cin >> N;
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    for(int i=0; i<N; i++){
        cin >> b[i];
    }

    sort(a, a+N);
    sort(b, b+N, compare);

    int ans = 0;
    for(int i=0; i<N; i++){
        ans = ans + a[i] * b[i];
    }
    cout << ans << endl;

    return 0;
}