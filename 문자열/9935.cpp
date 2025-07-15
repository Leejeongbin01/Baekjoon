#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string str, boom;
    cin >> str; cin >> boom;

    string ans = "";
    for(int i=0; i<str.size(); i++){
        ans+=str[i];
        if(ans.back()==boom.back()){
            if(ans.size() >= boom.size()){
                bool check=true;
                for(int j=0; j<boom.size(); j++){
                    if(ans[ans.size()-boom.size()+j]!=boom[j]){
                        check=false;
                        break;
                    }
                }

                if(check==true){
                    for(int j=0; j<boom.size(); j++){
                        ans.pop_back();
                    }
                }
            }
        }
    }
    
    if(ans.size()==0){
        cout << "FRULA" << endl;
    }   
    else{
        cout << ans << endl;
    }
    return 0;
}