#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int a; cin >> a;
            pq.push(a);
        }

        while(pq.size()>N){
            pq.pop();
        }
    }

    cout << pq.top() << "\n";
    return 0;
}