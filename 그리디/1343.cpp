#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string str;
    cin >> str;

    string ans = "";
    for(int i=0; i<str.size(); i++){
        //cout << "i : " << i <<"\n";
        if(str[i]=='.'){
            //cout << "here" << "i\n";
            ans += '.';
            continue;
        }

        bool flag4=true;
        if(i+3<str.size()){
            for(int j=i; j<i+4; j++){
                if(str[j]=='.'){
                    //cout << "i : " << i <<"\n";
                    flag4 = false;
                    break;
                }
            }
        }
        else{
            flag4=false;
        }

        bool flag2=true;
        if(i+1<str.size()){
            for(int j=i; j<i+2; j++){
                if(str[j]!='X'){
                    flag2=false;
                    break;
                }
            }
        }
        else{
            flag2=false;
        }

        if(flag4==true){
            ans += "AAAA";
            i+=3;
        }
        else if(flag2==true){
            ans += "BB";
            i+=1;
        }
        else{
            cout << "-1\n";
            return 0;
        }
    }
    cout << ans << "\n";
    return 0;
}