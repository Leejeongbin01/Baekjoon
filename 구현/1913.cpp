#include <iostream>
using namespace std;

int main()
{
    int N; cin >> N;
    int num; cin >> num;

    int arr[1002][1002]={0};

    int x=1,y=1;
    int w=0, s=0, e=0, n=0;
    w=1;
    for(int i=N*N; i>=1; i--){
        if(i==1) break;
        arr[x][y]=i;
        
        if(w==1){
            if(x < N && arr[x+1][y]==0){
                x++;
            }
            else{
                w=0; s=1;
                i++;
            }
        }
        else if(s==1){
            if(y < N && arr[x][y+1]==0){
                y++;
            }
            else{
                s=0; e=1;
                i++;
            }
        }
        else if(e==1){
            if(x > 1 && arr[x-1][y]==0){
                x--;
            }
            else{
                e=0; n=1;
                i++;
            }
        }
        else if(n==1){
            if(y > 1 && arr[x][y-1]==0){
                y--;
            }
            else{
                n=0; w=1;
                i++;
            }
        }
    }

    int H,W=0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(arr[i][j]==0) arr[i][j]=1;
            cout << arr[i][j] << " ";

            if(arr[i][j]==num){
                H = i; W = j;
            }
        }
        cout << endl;
    }
    cout << H << " " << W << endl;
    return 0;
}