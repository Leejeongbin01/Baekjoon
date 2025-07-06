#include <iostream>
#include <algorithm>
using namespace std;

vector<int> v;

int main()
{
    int N; cin >> N;
    for(int i=0; i<N;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    unique(v.begin(), v.end());
    for(int i=0; i<N; i++){
        cout << v[i] << "\n";
    }
    return 0;
}