#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> v;
    queue<int> q;
    for(int i=1; i<=N; i++){
        q.push(i);
    }

    
    while(!q.empty()){
        if(q.size()==1){
            v.push_back(q.front());
            q.pop();
            break;
        }
        else if(q.size() < K){
            int tmp = q.size() % K;
            int cnt = 0;
            while(1){
                cnt++;
                int tmp = q.front();
                q.pop();
                if(cnt == K){
                    v.push_back(tmp);
                    break;
                }
                q.push(tmp);
            }
        }
        else{
            int cnt = 0;
            while(1){
                cnt++;
                int tmp = q.front();
                q.pop();
                if(cnt == K){
                    v.push_back(tmp);
                    break;
                }
                q.push(tmp);
            }
        }
    }
    
    cout << "<";
	for (int i = 0; i < N-1; i++) {
		cout << v[i] << ", ";
	}
	cout << v[N - 1] << ">";
	return 0;
}