#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str; getline(cin,str);
    int strLen = str.size();
    stack<char> st;
    int flag=0;
    for(int i=0; i<strLen; i++){
        if(str[i]==' ' && flag==0){
            while(!st.empty()){
                char tmp = st.top();
                st.pop();
                cout << tmp;
            }
            cout << ' ';
        }
        else if(str[i]=='<'){
            flag=1;
            
            while(!st.empty()){
                char tmp = st.top();
                st.pop();
                cout << tmp;
            }
            cout << str[i];
        }
        else if(str[i]=='>'){
            flag=0;
            cout << str[i];
        }
        else{
            if(flag == 1){
                cout << str[i];
            }
            else{
                st.push(str[i]);
            }
        }
    }

    while(!st.empty()){
        char tmp = st.top();
        st.pop();
        cout << tmp;
    }
    return 0;
}