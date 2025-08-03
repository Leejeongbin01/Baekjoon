#include <iostream>
using namespace std;

int arr[4][4];
int ans = 1e9;

int checkMin(int a,int b, int c)
{
    int firstOrder = abs(a-b) + abs(a-c);
    int secondOrder = abs(b-a) + abs(b-c);
    int thirdOrder = abs(c-a) + abs(c-b);

    return min(min(firstOrder,secondOrder), thirdOrder);
}

int main()
{
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            cin >> arr[i][j];
        }
    }

    // check row
    for(int i=1; i<=3; i++){
        int cnt = checkMin(arr[i][1],arr[i][2],arr[i][3]);
        ans = min(ans,cnt);
    }

    // check col
    for(int i=1; i<=3; i++){
        int cnt = checkMin(arr[1][i],arr[2][i],arr[3][i]);
        ans = min(ans,cnt);
    }

    cout << ans << "\n";
    return 0;
}