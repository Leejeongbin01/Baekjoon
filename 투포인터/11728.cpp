#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;

    vector<int> a;
    vector<int> b;
    for(int i=0; i<N; i++){
        int tmp; cin >> tmp;
        a.push_back(tmp);        
    }
    for(int i=0; i<M; i++){
        int tmp; cin >> tmp;
        b.push_back(tmp);        
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> v(N+M,0);

    int idx=0;
    int ptrA=0;
    int ptrB=0;

    while(ptrA < N && ptrB < M){
        if(a[ptrA]<b[ptrB]){
            v[idx++]=a[ptrA];
            ptrA++;
        }
        else{
            v[idx++]=b[ptrB];
            ptrB++;
        }
    }

    while(ptrA < N){
        v[idx++] = a[ptrA++];
    }

    while(ptrB < M){
        v[idx++] = b[ptrB++];
    }

    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";

    return 0;
}