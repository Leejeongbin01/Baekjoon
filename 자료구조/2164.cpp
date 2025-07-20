#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N; cin >> N;
    queue<int> q;

    for(int i=1; i<=N; i++){
        q.push(i);
    }

    while(1){
        if(q.size()==1){
            cout << q.front() << endl;
            break;
        }
        else if(q.size() >= 2){
            q.pop();
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
    }
    return 0;
}