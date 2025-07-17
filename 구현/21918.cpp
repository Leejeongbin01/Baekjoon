#include <iostream>
using namespace std;

bool light[4001];

int main()
{
    int N,M; cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> light[i];
    }
    
    while(M--){
        int a,b,c;
        cin >> a >> b >> c;

        if(a==1){
            light[b] = c;
        }
        else if(a==2){
            for(int i=b; i<=c; i++){
                if(light[i]==false){
                    light[i]=true;
                }
                else{
                    light[i]=false;
                }
            }
        }
        else if(a==3){
            for(int i=b; i<=c; i++){
                light[i]=false;
            }
        }
        else if(a==4){
            for(int i=b; i<=c; i++){
                light[i]=true;
            }
        }
    }

    for(int i=1; i<=N; i++){
        cout << light[i] << " ";
    }
    cout << endl;
    return 0;
}