#include <iostream>
using namespace std;

int M,N,K;
int secret[101];
int user[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> K;
    for(int i=1; i<=M; i++){
        cin >> secret[i];
    }

    //cout << secret[0] << "\n";
    for(int i=1; i<=N; i++){
        cin >> user[i];
    }

    if(M>N){
        cout << "normal\n";
        return 0;
    }

    for(int i=1; i<=N-M; i++){
        bool check = true;
        int idx = 1;
       // cout << "\n";
        for(int j=i; j<i+M; j++){
            //cout << secret[idx] << " " << user[j] << "\n";
            if(secret[idx++]!=user[j]){
                check = false;
                break;
            }
        }

        if(check==true){
            cout << "secret\n";
            return 0;
        }
    }

    cout << "normal\n";
    return 0;
}