#include <iostream>
using namespace std;

int main()
{
    int T; cin >> T;
    while(T--){
        int N, D; cin >> N >> D;
        int arr[501][501] = {0};
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin >> arr[i][j];
            }
        }

        D = (D % 360 + 360) % 360;
        D = D / 45;
        //cout << endl << "D : " << D << endl;
        int a[501] = {0}; // 주대각선
        int b[501] = {0}; // 가운데열
        int c[501] = {0}; // 부대각선
        int d[501] = {0}; // 가운데행
        for(int i=0; i<N; i++){
                a[i] = arr[1+i][1+i];
                d[i] = arr[(N/2)+1][1+i];
                c[i] = arr[1+i][N-i];
                b[i] = arr[1+i][(N/2)+1];
        }

        for(int i=0; i<D; i++){
            int tmp[501];
            for(int j=0; j<N; j++) tmp[j] = a[j];
            for(int j=0; j<N; j++) a[j] = d[j];
            for(int j=0; j<N; j++) d[j] = c[N-1-j];
            for(int j=0; j<N; j++) c[j] = b[j];
            for(int j=0; j<N; j++) b[j] = tmp[j];
        }
        /*
        for(int i=0; i<N; i++){
            cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << endl;
        }
        cout << endl;
        */
        
        for(int i=1; i<=N; i++){
            arr[i][i] = a[i-1];
            arr[i][(N/2)+1] = b[i-1];
            arr[i][N-i+1] = c[i-1];
            arr[(N/2)+1][i] = d[i-1];
        }

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        //cout << endl;
    }

    return 0;
}