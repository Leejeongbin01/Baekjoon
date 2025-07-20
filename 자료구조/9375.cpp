#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        map<string, int> m;
        string str1, str2; 
        

        while(N--){
            cin >> str1 >> str2;
        if(m.find(str2)==m.end()){
            m.insert({str2, 1});
        }
        else{
            m[str2]++;
        }
    }
        int ans = 1;
        for(auto e : m){
            ans *= (e.second)+1;
        }
        
        cout << (ans-1) << "\n";
    }

    return 0;
}