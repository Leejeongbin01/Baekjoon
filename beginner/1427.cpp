#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main()
{
    long long N; cin >> N;
    vector<int> v;

    while(N!=0){
        int tmp = N % 10;
        N /= 10;

        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), compare);
    for(int i=0; i<v.size(); i++){
        cout << v[i];
    }
    cout << endl;

    return 0;
}