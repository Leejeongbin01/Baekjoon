#include <iostream>
#include <queue>
using namespace std;

int N;
deque<pair<int, long long>> curDQ, nextDQ;

// 앞에서 빼줘야하는 경우랑
// 뒤에서 빼줘야하는 경우 2가지가 있음.
// 앞에서 먼저 빼주다가, 뒤에서 빼줘도 되는 경우를 2가지를 고려한 후
// idx는 그냥 max값 사용하면 됨. 

int main()
{
    cin >> N;
    for(int i=0; i<N; i++){
        long long s;
        cin >> s;
        curDQ.push_back({i+1,s});
    }

    while(curDQ.size() > 1){
        while(!curDQ.empty()){
            int idx = curDQ.front().first;
            long long size = curDQ.front().second;
            curDQ.pop_front();

            // 1 2 3 같은 경우에는 뒷쪽에서도 탐색을 해줘야함
            while(!nextDQ.empty() && nextDQ.back().second <= size){
                size += nextDQ.back().second;
                idx = max(idx, nextDQ.back().first);
                nextDQ.pop_back();
            }

            // 3 2 1 같이 앞에서 빼줄떄
            while(!curDQ.empty() && curDQ.front().second <= size){
                size += curDQ.front().second;
                idx = max(idx, curDQ.front().first);
                curDQ.pop_front();
            }

            nextDQ.push_back({idx, size});
        }

        swap(curDQ, nextDQ);
        nextDQ.clear();
    }

    cout << curDQ.front().second << "\n";
    cout << curDQ.front().first << "\n";
    return 0;
}