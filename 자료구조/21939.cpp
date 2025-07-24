#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    set<pair<int,int>> s;
    map<int,int> m; // 정렬

    int N; cin >> N;
    for(int i=0; i<N; i++){
        int a,b; cin >> a >> b;
        s.insert({b,a});
        m[a]=b;
    }

    /*
    for(auto it : s){
        cout << it.first << " " << it.second << endl;
    }
    */
   
    int M; cin >> M;
    for(int i=0; i<M; i++){
        string str; cin >> str;
        if(str=="add"){
            int a,b; cin >> a >> b;
            s.insert({b,a});
            m[a]=b;
        }
        else if(str=="recommend"){
            int a; cin >> a;
            if(a==1){
                auto it = s.rbegin();
                cout << it->second << "\n";
            }
            else if(a==-1){
                auto it = s.begin();
                cout << it->second << "\n";
            }
        }
        else if(str=="solved"){
            int a; cin >> a;
            s.erase({m[a],a});
        }
    }

    return 0;
}