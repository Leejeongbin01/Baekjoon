#include <iostream>
using namespace std;

int main()
{
    int X; cin >> X;
    int line = 1;

    while(X - line > 0){
        X -= line;
        line ++;
    }

    if(line % 2){
        cout << line + 1 - X << "/" << X;
    }
    else{
        cout << X << "/" << line + 1 -X;
    }

    return 0;
}