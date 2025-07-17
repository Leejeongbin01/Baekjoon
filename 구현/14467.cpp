#include <iostream>
using namespace std;

bool first[101];
bool check[101];

int main()
{
    int N; cin >> N;
    int ans = 0;
    for(int i=0; i<N; i++){
        int cow, location;
        cin >> cow >> location;

        if(first[cow]==false){ // 처음
            first[cow]=true;
            check[cow]=location;
        }
        else{
            if(check[cow]!=location){
                ans++;
                check[cow]=location;
            }
        }
    }

    cout << ans << endl;
    return 0;
}