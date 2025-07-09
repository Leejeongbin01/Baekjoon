#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> v;
    int check=0;
    for(int i=0; i<5; i++){
        string tmp; cin >> tmp;
        v.push_back(tmp);
    }

    for(int i=0; i<5; i++){
        if(check < v[i].size()){
            check = v[i].size();
        }
    }
    string ans = "";
    for(int i=0; i<check; i++){
        for(int j=0; j<5; j++){
            if(i < v[j].size())
                ans += v[j][i];
        }
    }

    cout << ans << endl;
    return 0;
}