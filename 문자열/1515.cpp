#include <iostream>
using namespace std;

int main()
{
    string str; cin >> str;

    /*
    int prev = 1;
    for(int i=0; i<str.size(); i++){
        int flag = 0;
        for(int j=prev; j<=3001; j++){
            string s = to_string(j);
            for(int k=0; k<s.size(); k++){
                if(s[k]==str[i]){
                    prev = j+1;
                    flag = 1;
                    break;
                }
            }

            if(flag==1){
                break;
            }
        }
    }
    cout << prev << endl;
    */

    int num = 1;
    int idx = 0;
    while(1){
        string s = to_string(num);
        for(char c : s){
            if(c == str[idx]){
                idx++;
                if(idx == str.size()){
                    cout << num << endl;
                    return 0;
                }
            }
        }
        num++;
    }
    
    return 0;
}