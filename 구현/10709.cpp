#include <iostream>
using namespace std;

int main()
{
    int H,W; cin >> H >> W;
    int arr[101][101] = {-1};
    for(int i=0; i<H; i++){
        string str; cin >> str;
        for(int j=0; j<W; j++){
            if(str[j]=='c'){
                arr[i][j]=0;
            }
            else{
                arr[i][j]=-1;
            }
        }
    }  

    /*
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    */

    int idx;
    for(int i=0; i<H; i++){
        idx = -1;
        for(int j=0; j<W; j++){
            if(arr[i][j]==0){
                idx = 0;
                continue;
            }

            if(idx == -1) continue;
            arr[i][j] = ++idx;
        }
    }

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}