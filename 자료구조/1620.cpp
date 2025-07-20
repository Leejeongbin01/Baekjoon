#include <iostream>
#include <map>
#include <cctype>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(0);
    int N,M; cin >> N >> M;
    map<string, int> m;
    string arr[100000];
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        m.insert({arr[i],i});
    }

    while(M--){
        string str; cin >> str;
        if(isdigit(str[0]) != 0){
            int tmp = stoi(str);
            cout << arr[tmp] << "\n";
        }
        else{
            auto idx = m.find(str);
            cout << idx->second << "\n";
        }
    }
    return 0;
}