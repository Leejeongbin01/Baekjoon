#include <iostream>
using namespace std;

int main()
{
    int money; cin >> money;
    int price[15];
    for(int i=0; i<14; i++){
        cin >> price[i];
    }

    int a = 0;
    int a_money = money;
    int b_money = money;
    for(int i=0; i<14; i++){
        int tmp = a_money / price[i];
        if(tmp==0) continue;

        a += tmp;
        a_money = a_money % price[i];
    }

    int down = 0, up = 0;
    int b = 0;
    for(int i=1; i<14; i++){
        if(price[i-1] < price[i]){
            up++;
            down = 0;
        }
        else if(price[i-1] > price[i]){
            down++;
            up = 0;
        }

        if(up >= 3){
            if(b > 0){
                b_money = b_money + price[i] * b;
                b = 0;
            }
        }
        else if(down >= 3){
            int tmp = b_money / price[i];
            if(tmp==0) continue;

            b += tmp;
            b_money = b_money % price[i];
        }
    }

    int a_ans = a * price[13] + a_money;
    int b_ans = b * price[13] + b_money;

    //cout << endl << "------------" << endl;
    //cout << a_ans << " "  << b_ans << endl;
    //cout << "b : " << b << " b_money : " << b_money << endl;

    if(a_ans > b_ans){
        cout << "BNP" << endl;
    }
    else if(a_ans < b_ans){
        cout << "TIMING" << endl;
    }
    else{
        cout << "SAMESAME" << endl;
    }

    return 0;
}