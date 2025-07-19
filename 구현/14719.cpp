#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int H,W; cin >> H >> W;
    int arr[501][501];
    int save[501];
    memset(arr,-1,sizeof(arr));
    for(int i=0; i<W; i++){
        int a; cin >> a;
        save[i] = a;
        for(int j=0; j<a; j++){
            arr[H-1-j][i]=1;
        }
    }

    int wall = save[0];
    int ans = 0;
    for(int i=1; i<W; i++){
        int tmp_idx = -1;
        int bad_idx = -1;
        int bad_wall = -1;
        
        for(int j=i; j<W; j++){
            if(save[j]==0) continue;
            if(save[j]>=wall){
                tmp_idx = j;
                break;
            }
            else{
                if(save[j] > bad_wall){
                    bad_wall = save[j];
                    bad_idx = j;
                }
            }
        }

        if(tmp_idx!=-1) { // find
            //cout << "tmp idx : " << tmp_idx << endl;
            for(int j=i; j<tmp_idx; j++){
                ans += wall - save[j];
            }
            i = tmp_idx;
            wall = save[tmp_idx];
        }
        else if(tmp_idx == -1 && bad_idx != -1){ // bad find
            //cout << "bad idx : " << bad_idx << endl;
            for(int j=i; j<bad_idx; j++){
                ans += bad_wall - save[j];
            }
            i = bad_idx;
            wall = save[bad_idx];
        }
        
    }

    cout << ans << endl;
    return 0;
}