#include <iostream>
#include <cstring>
using namespace std;

int N,M;
int arr[100001];


int main()
{
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        int a; cin >> a;
        arr[i] = a;
    }
    int rank[100001];
    memset(rank,-1,sizeof(rank));

    int result = 0;
    while(M--){
        int a,b; cin >> a >> b;
        if(arr[a] > arr[b]){
            rank[b]=0;
        }
        else if(arr[a] < arr[b]){
            rank[a]=0;
        }
        else{
            rank[a]=0;
            rank[b]=0;
        }
    }    

    for(int i=1; i<=N; i++){
        if(rank[i]==-1) result++;
    }
    cout << result << "\n";
    return 0;
}