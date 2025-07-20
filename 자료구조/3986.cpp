#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int N; cin >> N;
    int ans = 0;
    while(N--){
        string str; cin >> str;
        stack<char> stack;

        for(int i=0; i<str.size(); i++){
            if(stack.empty()){
                stack.push(str[i]);
            }
            else{
                if(str[i]==stack.top()){
                    stack.pop();
                }
                else{
                    stack.push(str[i]);
                }
            }
        }
        if(stack.empty()){
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}