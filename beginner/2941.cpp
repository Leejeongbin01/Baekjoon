#include <iostream>
using namespace std;

int main()
{
    string str; cin >> str;
    string arr[8] = {"c=","c-","dz=","d-","lj","nj","s=","z="};

    for(int i=0; i<8; i++){
        while(1){
            int idx = str.find(arr[i]);
            if(idx==string::npos){
                break;
            }

            str.replace(idx, arr[i].length(), "#");
        }
    }

    cout << str.length();

    return 0;
}