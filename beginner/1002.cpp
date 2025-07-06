#include <iostream>
using namespace std;

int main()
{
    int T; cin >> T;
    while(T--){
        int x1,y1,r1;
        int x2,y2,r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int d = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
        int tmp1 = (r1-r2)*(r1-r2);
        int tmp2 = (r1+r2)*(r1+r2);

        if(d==0){
            if(tmp1 == 0){
                cout <<"-1\n";
            }else{
                cout <<"0\n";
            }
        }
        else if(d==tmp1 || d==tmp2){
            cout << "1\n";
        }
        else if(tmp1 < d && d < tmp2){
            cout << "2\n";
        }
        else{
            cout << "0\n";
        }
    }
}