#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[1000001];
vector<int> v;

int bin_search(int x)
{
    int L = 0;
    int R = v.size()-1;
    int mid = -1;

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

    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }


    // 크기가 커지는 순서만 알면된다. 
    // 10 20 30 25 를 만나면 기존의 사이즈에 25의 idx를 찾아줘야하는데, 이떄 bs를 씀
    // 아닐 경우, 그냥 직선으로 v에 담고
    v.push_back(arr[1]);
    for(int i=2; i<=N; i++){
        int tmp = arr[i];
        // cout << v.back() << " " << tmp << "\n";
        if(v.back() < tmp){
            v.push_back(tmp);
        }
        else{
            int idx = bin_search(tmp);
            v[idx]=tmp;
        }
    }
    
    /*
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
    */
    
    cout << v.size() << "\n";
    return 0;
}