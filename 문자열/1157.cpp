#include <iostream>
using namespace std;

int main()
{
    string str; cin >> str;
    int c[26] = {0,};

    for(int i=0; i<str.size(); i++){
        if(str[i]<97){
            c[str[i]-65]++;
        }
        else{
            c[str[i]-97]++;
        }
    }

    int max = 0; int idx = 0;
    for(int i=0; i<26; i++){
        if(max < c[i]){
            max = c[i];
            idx = i;
        }
    }

    int flag = 0;
    for(int i=0; i<26; i++){
        if(max==c[i]){
            flag++;
        }
    }

    if(flag >= 2){
        cout << "?";
    }
    else{
        cout << (char)(idx+65);
    }
}