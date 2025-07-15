#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M; // 듣도, 보도
    cin >> N >> M;

    vector<string> v1,v2;
    for(int i=0;  i<N; i++){
        string tmp; cin >> tmp;
        v1.push_back(tmp);
    }
    sort(v1.begin(), v1.end());

    while(M--){
        string tmp; cin >> tmp;
        if(binary_search(v1.begin(), v1.end(), tmp)){ // 이분탐색
            v2.push_back(tmp);
        }
    }
    sort(v2.begin(), v2.end());
    cout << v2.size() << endl;
    for(int i=0; i<v2.size(); i++){
        cout << v2[i] << endl;
    }

    return 0;
}