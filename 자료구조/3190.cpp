#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int arr[102][102];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
// 동, 서, 남, 북
deque<pair<int, int>> dq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N; cin >> N;
    int K; cin >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            arr[i][j]=1;
        }
    }

    for(int i=0; i<K; i++){
        int row, col; cin >> row >> col;
        arr[row][col]=2;
    }

    vector<pair<int, int>> v;
    int L; cin >> L;
    for(int i=0; i<L; i++){
        int X; char C; 
        cin >> X >> C;
        v.push_back({X,C});
    }

    int v_idx = 0;
    dq.push_back({1,1});
    int direction = 0;
    int time = 0;

    while(1){
        time++;
        int tmpX = dq.front().first;
        int tmpY = dq.front().second;
        // cout << " time : " << time;
        // cout << " dir : " << direction;
        // cout << ", " <<  tmpX << " " << tmpY;
        // cout << ", dq size " << dq.size() << endl;

        tmpX += dx[direction];
        tmpY += dy[direction];
        
        if(tmpX<1 || tmpY<1 || tmpX>N || tmpY > N){
            break;
        }

        bool isbody=false;
        for(int j=0; j<dq.size(); j++){
            if(tmpX==dq[j].first && tmpY==dq[j].second){
                isbody=true;
                break;
            }
        }
        if(isbody) break;

        if(arr[tmpX][tmpY]==2){
            dq.push_front({tmpX,tmpY});
            arr[tmpX][tmpY]=1;
        }
        else{
            dq.pop_back();
            dq.push_front({tmpX,tmpY});
            arr[tmpX][tmpY]=1;
        }

        if(time==v[v_idx].first){
            if(v[v_idx].second=='D'){
                if(direction==0) direction=2;
                else if(direction==1) direction=3;
                else if(direction==2) direction=1;
                else if(direction==3) direction=0;
            }
            else if(v[v_idx].second=='L'){
                if(direction==0) direction=3;
                else if(direction==1) direction=2;
                else if(direction==2) direction=0;
                else if(direction==3) direction=1;
            }
            v_idx++;
        }
    }

    cout << time << "\n";
    return 0;
}