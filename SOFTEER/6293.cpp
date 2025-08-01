#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[3001];
vector<int> v;

int isIdx(int x)
{
    //cout << x << endl;
    //cout << v.size() << endl;
    int L = 0;
    int R = v.size() - 1;

    int mid=-1;
    while(L<R){
        mid = (L+R)/2;

        if(v[mid] >= x){
            R = mid;
        }
        else{
            L = mid+1;
        }

        //cout << "h" << endl;
    }
    return R;
}

int main()
{
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }

    // 매번 확인하면서 내부의 이분탐색 조지는거임. 
    v.push_back(arr[1]);
    for(int i=2; i<=N; i++){
        int tmp = arr[i];
        if(v.size()==1){
            if(v.back() > tmp){
                v[0] = tmp;
                continue;
            }
        }

        if(v.back() > tmp){
            int idx = isIdx(tmp);
            v[idx] = tmp;
        }
        else{
            v.push_back(tmp);
        }
    }
    
    cout << v.size() << "\n";
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";

    }
    cout << "\n";
    return 0;
}