#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while(T--){
        int flag = 0;
        string str;
        stack<char> sta;
        cin >> str;

        for(int i=0; i<str.size(); i++){
            char tmp = str[i];
            if(tmp == '('){
                sta.push('(');
            }
            else if(tmp == ')'){
                if(!sta.empty()){
                    sta.pop();
                }
                else{
                    flag = 1;
                    cout << "NO" << endl;
                    break;
                }
            }
        }

        if(!sta.empty()){
            cout << "NO" << endl;
        }
        else if(sta.empty() && flag==0){
            cout << "YES" << endl;
        }
    }

    return 0;
}