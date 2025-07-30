#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string str="";
    for(int i=0; i<8; i++){
        int a; cin >> a;
        str += to_string(a);
        //str += a + '0';
    }
    cout << str << endl;

    if(str=="12345678"){
        cout << "ascending\n";
    }
    else if(str=="87654321"){   
        cout << "descending\n";
    }
    else{
        cout << "mixed\n";
    }
    return 0;
}