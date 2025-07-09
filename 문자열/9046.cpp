#include <iostream>
using namespace std;

int main()
{
    string a = "abcdefghijklmnopqrstuvwxyz";
    string b = "wghuvijxpqrstacdebfklmnoyz";

    int T; cin >> T; cin.ignore();
    while(T--){
        string str; 
        getline(cin,str);
        char c[26]={0,};

        for(int i=0; i<str.size(); i++){
            if(str[i]==' '){
                continue;
            }

            c[str[i] - 'a']++;
        }

        int ans = 0;
        int idx = 0;
        for(int i=0; i<26; i++){
            if(ans < c[i]){
                ans = c[i];
                idx = i;
            }
        }

        int flag = 0;
        for(int i=0; i<26; i++){
            if(c[i]==ans){
                flag++;
            }
        }

        if(flag >= 2){
            cout << '?' << endl;
        }
        else{
            char tmp = 'a';
            tmp += idx;
            cout << tmp << endl;
        }
    }
    return 0;
}