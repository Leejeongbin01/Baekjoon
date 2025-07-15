#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str; cin >> str;
    int strLen = str.size();

    // 1. validate about string str
    char alphabet[26] = {0,};
    for(int i=0; i<strLen; i++){
        alphabet[str[i]-'A']++; // 대문자
    }
    
    int oddCheck = 0;
    int oddIdx = 0;
    if(strLen%2 == 0){ // even
        for(int i=0; i<26; i++){
            if(alphabet[i]%2==1){ // odd이면
                cout << "I'm Sorry Hansoo" << endl;
                return 0;
            }
        }
    }
    else{ // odd
        for(int i=0; i<26; i++){
            if(alphabet[i]%2==1){ // odd이면
                oddCheck++;
                oddIdx = i;
                if(oddCheck >=2){
                    cout << "I'm Sorry Hansoo" << endl;
                    return 0;
                }
            }
        }
    }

    // 2. 팰린드롬 수 구하기
    stack<char> st;
    string ans = "";
    if(strLen%2==0){ // even
        for(int i=0; i<26; i++){
            if(alphabet[i]==0) continue;

            int tmp = alphabet[i]/2;
            for(int j=0; j<tmp; j++){
                ans += (char)(i+'A');
                st.push(char(i+'A'));
            }
        }

        while(!st.empty()){
            char c = st.top();
            st.pop();
            ans += c;
        }
    }
    else{   // odd
        for(int i=0; i<26; i++){
            if(alphabet[i]==0) continue;
            
            int tmp = alphabet[i]/2;
            for(int j=0; j<tmp; j++){
                ans += (char)(i+'A');
                st.push(char(i+'A'));
            }
        }

        ans += (char)(oddIdx+'A');
        while(!st.empty()){
            char c = st.top();
            st.pop();
            ans += c;
        }
    }

    cout << ans << endl;
    return 0;
}