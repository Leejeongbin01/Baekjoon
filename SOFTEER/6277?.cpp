#include <iostream>
#include <utility>
using namespace std;

int N,M;
int visit[21]; // 아직 안먹음 = 0, 먹는중 = 1, 다먹고 감 = 2
pair<int, int> eachDesk[21]; // 각 숫자의 앉은 자리 저장
int desk[21][21]; // -1 : 앉으면 안됨, 1 : 앉고있음. 0 : 앉아도됨. 
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
bool seat_first;

bool check_seat(int n)
{
    int best_x=-1, best_y=-1;
    int best_dist = -1;
    if(seat_first==false){
        seat_first=true;
        eachDesk[n].first = 1;
        eachDesk[n].second =1;
        desk[1][1]=1;
        visit[n]=1;
        return true;
    }
    else{
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                if(desk[i][j]!=0) continue;
                if(desk[i][j-1]==1 || desk[i][j+1]==1 || desk[i-1][j]==1 || desk[i+1][j]==1) continue;

                int min_dist = 1e8;
                for(int k=1; k<=20; k++){
                    if(visit[k]==1){
                        int x = i-eachDesk[k].first;
                        int y = j-eachDesk[k].second;
                        min_dist = min(min_dist, x*x+y*y);
                    }
                }

                //cout << i << " " << j << " " << min_dist << "\n";
                if(min_dist > best_dist){
                    best_dist = min_dist;
                    best_x = i;
                    best_y = j;
                }
                else if(min_dist == best_dist){
                    if(i < best_x || (best_x==i && j < best_y)){
                        best_x = i;
                        best_y = j;
                    }
                }
            }
        }
    }

    if(best_dist == -1) return false;

    eachDesk[n] = {best_x, best_y};
    desk[best_x][best_y]=1;
    visit[n]=1;
    desk[best_x+1][best_y]=-1;
    desk[best_x-1][best_y]=-1;
    desk[best_x][best_y+1]=-1;
    desk[best_x][best_y-1]=-1;

    return true;
}

void remove_seat(int n)
{
    int x = eachDesk[n].first;
    int y = eachDesk[n].second;
    desk[x][y]=0;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(desk[i][j]!=1) desk[i][j]=0;
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(desk[i][j]==1){
                for(int k=0; k<4; k++){
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    desk[nx][ny]=-1;
                }
            }
        }
    }
}

int main()
{
    // In
    // 아직 안먹었으면 -> 자리 배정(*)
    // 먹고있는지는 visit로 관기기
    // 다 먹었는지는 visit로

    // Out
    // 안왔으면 -> 아직 안옴.
    // 자리 빼주기(*)
    // 이미 먹고갔으면 갔음. 
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> N >> M >> T;
    cout << "\n";

    while(T--){
        string str;
        int a;
        cin >> str >> a;

        if(str=="In"){
            if(visit[a]==0){
                if(check_seat(a)){
                    cout << a << " gets the seat (";
                    cout << eachDesk[a].first << ", " << eachDesk[a].second << ").\n";
                }
                else{
                    cout << "There are no more seats\n";
                }
            }
            else if(visit[a]==1){
                cout << a << " already seated.\n";
            }
            else if(visit[a]==2){
                cout << a << " already ate lunch.\n";
            }
        }
        else if(str=="Out"){
            if(visit[a]==0){
                cout << a << " didn't eat lunch.\n";
            }
            else if(visit[a]==1){
                remove_seat(a);
                visit[a]=2;
                cout << a << " leaves from the seat (" << eachDesk[a].first << ", ";
                cout << eachDesk[a].second <<").\n";
            }
            else if(visit[a]==2){
                cout << a << " already left seat.\n";
            }
        }
    }
    
    return 0;
}