#include <iostream>
using namespace std;

int main()
{
    char m[5] = {'a','e','i','o','u'};

    while(1){
        string str; cin >> str;
        if(str == "end"){
            break;
        }
        int flag1 = 0;
        int flag2_m = 0, flag2_j = 0;
        int flag2 = 0;
        int flag3 = 0;

        for(int i=0; i<str.size(); i++){
            if(!(str[i]=='e'|| str[i]=='o')){
                if(i+1 < str.size() && str[i]==str[i+1]){
                    flag3++;
                }
            }

            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
                flag1++;
                flag2_m++;
                flag2_j = 0;
                if(flag2_m==3){
                    flag2++;
                }
            }
            else{
                flag2_j++;
                flag2_m = 0;
                if(flag2_j==3){
                    flag2++;
                }
            }
        }

        if(flag1 >= 1 && flag2==0 && flag3==0){
            cout << "<" << str << "> is acceptable.\n";
        }
        else{
            cout << "<" << str << "> is not acceptable.\n";
        }

        
    }

    return 0;
}