#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vector<int> v; // 각 시간대를 넣는거
    vector<pair<int,int>> input; // 실제 입력
    for(int i=0; i<N; i++){
        int a,b; cin >> a >> b;
        input.push_back({a,b});
        v.push_back(a);
        v.push_back(b);
    }
    sort(v.begin(), v.end()); 
    v.erase(unique(v.begin(), v.end()), v.end());
    // 시간대별로 정리하고 중복은 다 삭제
    // 들어온 시간과 나간 시간을 알 수 있음. 
    
    // 그러면 들어간 시간에 해당하는 값은 +1, 나간 시간이면 -1을 해주면됨
    vector<int> rev(v.size()), sum(v.size());
    for(auto& i : input){
        int val1 = lower_bound(v.begin(), v.end(), i.first) - v.begin();
        int val2 = lower_bound(v.begin(), v.end(), i.second) - v.begin();
        // v[i]{a,b}가 처음 나오는 값
        // 2, 16이면 2가 처음 나오는 v의 위치 ->0
        // 16이 처음 나오는 v의 위치 -> 0
        //cout << i.first <<" " << i.second << endl;
        //cout << val1 << " " << val2 << endl;

        rev[val1]=i.first; // rev[0]=2;
        rev[val2]=i.second; // rev[4]=16
        sum[val1]++; // 들어간것과 나간것을 구분
        sum[val2]--;
    }

    for(int i=1; i<sum.size(); i++){
        sum[i]+=sum[i-1];
    }
    // 누적합을 사용함. 변화량을 누적하기 위해서임.
    // 한 마리 들어오고 다음에 한마리 들어오고, 빠져나간것을 1,2,2,1,0 이렇게 기록이 됨. 

    int res = 0;
    for(auto& i:sum){
        res = max(res,i);
    }
    cout << res <<"\n";

    int em,xm;
    bool flag = false;
    for(int i=0; i<sum.size(); i++){
        if(flag==false && sum[i]==res){
            flag = true;
            em = rev[i];
        }

        if(flag&&sum[i] != res){
            xm = rev[i];
            break;
        }
    }

    cout << em << " " << xm;
    return 0;
}