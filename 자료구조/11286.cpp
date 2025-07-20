#include <iostream>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(int x, int y)
    {
        if(abs(x)==abs(y)){
            return x > y;
        }
        else{
            return abs(x) > abs(y);
        }
    }
};



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL); 
    cout.tie(NULL);
    priority_queue<int, vector<int>, cmp> pq;
    int N; cin >> N;
    while(N--){
        int a; cin >> a;
		if (a != 0) {
			pq.push(a);
		}
		else if (a == 0) {
			if (pq.size() == 0) {
				cout <<  "0\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
    }
}