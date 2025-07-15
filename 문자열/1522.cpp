#include <iostream>
using namespace std;

int main()
{
    string str; cin >> str;
    int strLen = str.length();
    int aCount = 0, bCount = 0;
    for(int i=0; i<strLen; i++){
        if(str[i]=='a') aCount++;
        if(str[i]=='b') bCount++;
    }
    int minB = bCount;
    
    /*
    str += str;
    for(int i=0; i<str.size() - aCount; i++){
        int tmp = 0;
        for(int j=i; j<aCount+i; j++){
            if(str[j]=='b'){
                tmp++;
            }
        }
        minB = min(minB, tmp);
    }
    */

    for(int i=0; i<str.size(); i++){
        int cnt = aCount;
        int tmp = 0;
        for(int j=i; j<i+str.size(); j++){
            if(cnt == 0) break;
            if(str[j%str.size()]=='b') tmp++, cnt--;
            else cnt--;
        }
        minB = min(minB, tmp);
    }


    cout << minB << endl;
    return 0;
}