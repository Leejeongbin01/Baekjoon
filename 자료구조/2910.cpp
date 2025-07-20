#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
unordered_map<int, int> um;
bool cmp(int a, int b)
{
    if(um[a]!=um[b]){
        return um[a]>um[b];
    }

    return false;
}

int main()
{
    int N, C; cin >> N >> C;
    
    vector<int> order;

    for(int i=0; i<N; i++){
        int a; cin >> a;
        if(um[a]==0){
            order.push_back(a);
        }
        um[a]++;
    }

    stable_sort(order.begin(), order.end(), cmp);
    for(int x : order){
        for(int i=0; i<um[x]; i++){
            cout << x << " ";
        }
    }

    cout << endl;
    return 0;
}