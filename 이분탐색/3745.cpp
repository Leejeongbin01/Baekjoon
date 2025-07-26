#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int arr[100001];

int bs(int x, vector<int> &v)
{
    int L=0, R = v.size()-1;
    int mid=-1;

    while(L<R){
        mid = (L+R)/2;
        int tmp = v[mid];
        if(tmp >= x){
            R = mid;
        }
        else{
            L = mid+1;
        }
    }

    return R;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> N){
        memset(arr,0,sizeof(arr));
        for(int i=1; i<=N; i++){
            cin >> arr[i];
        }

        vector<int> v;
        v.push_back(arr[1]);
        for(int i=2; i<=N; i++){
            int tmp = arr[i];
            if(v.back() < tmp){
                v.push_back(tmp);
            }
            else{
                int idx = bs(tmp, v);
                v[idx]=tmp;
            }
        }

        cout << v.size() << "\n";
    }


    return 0;
}