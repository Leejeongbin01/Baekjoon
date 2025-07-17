#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> &a, pair<int,int> &b)
{
    return a.first > b.first;
}

int main()
{
    int N; cin >> N;
    int value[51][2] = {0};
    int ans[51];
    for(int i=0; i<N; i++){
        cin >> value[i][0] >> value[i][1];
        ans[i] = 1;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(value[i][0] < value[j][0] && value[i][1] < value[j][1]){
                ans[i]++;
            }
        }
    }

    for(int i=0; i<N; i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}