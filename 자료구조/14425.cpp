#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N,M; cin >> N >> M;
    set<string> set;
    for(int i=0; i<N; i++){
        string str; cin >> str;
        set.insert(str);
    }

    vector<string> v(set.begin(), set.end());
    /*
    for(auto it : v){
        cout << it << endl;
    }
    cout << endl;
    */
    int ans = 0;
    for(int i=0; i<M; i++){
        string str; cin >> str;
        if(binary_search(v.begin(), v.end(), str)){
            ans++;
        }
    }
    
    cout << ans;
    return 0;
}