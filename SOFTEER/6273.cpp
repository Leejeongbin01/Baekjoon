#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,K;

int main()
{
    cin >> N >> M >> K;
    vector<int> v;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int result=1e9;
    do{
        int w=0;
        int tmp=0;
        int idx=0;
        for(int i=0; i<K; i++){
            while(tmp + v[idx%N] <=M ){
                tmp += v[idx%N];
                idx++;
            }

            w+=tmp;
            tmp=0;
            if(w > result){
                break;
            }
        }


        result = min(result, w);
    }while(next_permutation(v.begin(), v.end()));

    cout << result;
}