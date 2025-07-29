#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N,M;
int g[501][501];
int indegree[501];

void t_sort()
{
    queue<int> q;
    vector<int> v;
    for(int i=1; i<=N; i++){
        if(indegree[i]==0) q.push(i);
    }

    if(q.size()==0){
        cout << "IMPOSSIBLE\n";
        return;
    }

    

    if(q.size()>1){
        cout << "?\n";
        return;
    }

    for(int k=0; k<N; k++){
        if(q.empty()){
            cout << "IMPOSSIBLE\n";
            return;
        }

        if(q.size() > 1){
            cout << "?\n";
            return;
        }

        int now = q.front();
        q.pop();
        v.push_back(now);
        
        for(int i=1; i<=N; i++){
            if(g[now][i]==1){
                g[now][i]=0;
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
    }

    for(int i=0; i<v.size(); i++){
        cout << v[i] << " "; 
    }
    cout << "\n";

    return;
}


int main()
{
    int T; cin >> T;
    while(T--){
        memset(g,0,sizeof(g));
        memset(indegree,0,sizeof(indegree));

        // 1. last year
        cin >> N;
        vector<int> save;
        for(int i=0; i<N; i++){
            int a; cin >> a;
            save.push_back(a);
            indegree[a]=i;
        }

        for(int i=0; i<N-1; i++){
            int tmp = save[i];
            for(int j=i+1; j<N; j++){
                g[tmp][save[j]]=1;
            }
        }

        // 2. this year
        cin >> M;
        for(int i=0; i<M; i++){
            int a,b; cin >> a >> b;
            if(g[a][b]==1){
                g[a][b]=0;
                g[b][a]=1;
                indegree[a]++;
                indegree[b]--;
            }
            else if(g[b][a]==1){
                indegree[a]--;
                indegree[b]++;
                g[a][b]=1;
                g[b][a]=0;
            }
        }

        // 3. check indegree[]
        /*
        cout << "\ncheck indegree \n";
        for(int i=1; i<=N; i++){
            cout << indegree[i] << " ";
        }
        cout << "\n";

        // 3-2. check graph
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cout << g[i][j] <<" ";
            }
            cout << "\n";
        }
        */
        // 4. topological sort
        t_sort();
        //cout << endl;
    }

    return 0;
}