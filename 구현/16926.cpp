#include <iostream>
using namespace std;

int main()
{
    int N,M,R; cin >> N >> M >> R;
    int arr[301][301] = {0};
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    int layer = min(N,M)/2;
    for(int r=0; r<R; r++){
        for(int i=0; i<layer; i++){
            int tmp=arr[i][i];
            for(int j=i; j<M-1-i; j++){
                arr[i][j] = arr[i][j+1];
            }
            for(int j=i; j<N-1-i; j++){
                arr[j][M-1-i] = arr[j+1][M-1-i];
            }
            for(int j=M-1-i; j>i; j--){
                arr[N-1-i][j]=arr[N-1-i][j-1];
            }
            for(int j=N-1-i; j>i; j--){
                arr[j][i]=arr[j-1][i];
            }

            arr[i+1][i]=tmp;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}