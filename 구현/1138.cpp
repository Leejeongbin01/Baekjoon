#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N; cin >> N;
    int arr[10] = {0};

    for(int i=1; i<=N; i++){
        int input, count = 0;
        int pnt = 0;
        cin >> input;
        while(count < input){
            if(arr[pnt]==0){
                count++;
            }
            pnt++;
        }
        while(arr[pnt]!=0) pnt++;
        arr[pnt] = i;
    }

    for(int i=0; i<N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}