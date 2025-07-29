#include <iostream>
#include <vector>
using namespace std;

int arr[26][26];
int N,M;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int dx2[4] = {0,0,2,-2};
int dy2[4] = {2,-2,0,0};
bool visit[26][26];
vector<int> v;

void dfs(int x, int y)
{
    if(visit[x][y]==true){
        return;
    }

    visit[x][y]=true;
    for(int i=0; i<4; i++){
        int nx1= x+dx[i];
        int ny1= y+dy[i];

        int nx2= x+dx2[i];
        int ny2= y+dy2[i];
        if(nx2>0 && ny2>0 && nx2<=N && ny2<=M){
            if(arr[nx1][ny1]==1 && arr[nx2][ny2]==1){
                if(visit[nx1][ny1]==false && visit[nx2][ny2]==false){
                    visit[nx1][ny1]=true;
                    visit[ny2][ny2]=true;
                    v.push_back(i);
                    dfs(nx2,ny2);
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. input
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        string str;
        cin >> str;
        for(int j=1; j<=M; j++){
            if(str[j-1]=='#'){
                arr[i][j]=1;
            }
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    // 2. search starting point
    int startX=-1,startY=-1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(arr[i][j]==1){
                int check = 0;
                for(int k=0; k<4; k++){
                    if(arr[i+dx[k]][j+dy[k]]==1){
                        check++;
                    }       
                }

                if(check==1){
                    startX = i, startY=j;
                    break;
                }
            }
        }
        if(startX!=-1 && startY!=-1){
            break;
        }
    }
    cout << startX << " " << startY << "\n";

    // 3.dfs()
    dfs(startX, startY);
    
    // 4. answer
    if(v[0]==0){
        cout << ">\n";
    }
    else if(v[0]==1){
        cout << "<\n";
    }
    else if(v[0]==2){
        cout << "V\n";
    }
    else if(v[0]==3){
        cout << "^\n";
    }

    cout << "A";
    int prev = v[0];
    for(int i=1; i<v.size(); i++){
        if(prev==v[i]){
            cout << "A";
        }
        else{
            if(prev==0){
                if(v[i]==2){
                    cout << "RA";
                }
                else if(v[i]==3){
                    cout << "LA";
                }
            }
            else if(prev==1){
                if(v[i]==2){
                    cout << "LA";
                }
                else if(v[i]==3){
                    cout << "RA";
                }
            }
            else if(prev==2){
                if(v[i]==0){
                    cout << "LA";
                }
                else if(v[i]==1){
                    cout << "RA";
                }
            }
            else if(prev==3){
                if(v[i]==0){
                    cout << "RA";
                }
                else if(v[i]==1){
                    cout << "LA";
                }
            }
        }

        prev = v[i];
    }

    cout << "\n";
    return 0;
}