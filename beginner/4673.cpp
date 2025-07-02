#include <iostream>
using namespace std;

int find(int x)
{
    int num = x;
    while(x!=0){
        num = num + (x%10);
        x = x/10;
    }
    
    return num;
}

int main()
{
    int n;
    bool check[10001] = {false,};

    for(int i=1; i<=10000; i++){
        n = find(i);

        if(n <= 10000){
            check[n] = true;
        }
    }

    for(int i=1; i<=10000; i++){
        if(check[i]==false){
            cout << i << endl;
        }
    }

    return 0;
}