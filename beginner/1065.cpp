#include <iostream>
using namespace std;

bool check(int x)
{
    if(x <= 99){
        return true; 
    }
    else{
        int tmp1 = x % 10;
        x = x/10;

        int tmp2 = x % 10;
        x = x/10;

        int diff = tmp2-tmp1;
        while(x!=0){
            int tmp3 = x % 10;
            x = x/10;
            if(diff==(tmp3-tmp2)){
                tmp2=tmp3;
            }
            else{
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int N;
    cin >> N;

    int cnt=0;
    for(int i=1; i<=N; i++){
        if(check(i)){
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}