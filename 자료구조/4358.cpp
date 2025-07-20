#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(4);

    map<string, int> m;
    string str;
    int cnt = 0;
    while(getline(cin,str)){
        cnt++;
        m[str]++;
    }
    
    for(auto e : m){
        cout << e.first << " " << (double)e.second/cnt*100 << "\n";
    }

    return 0;
}