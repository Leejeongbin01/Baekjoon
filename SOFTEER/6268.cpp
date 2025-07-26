#include <iostream>
using namespace std;

string arr[5];
string arr2[5];

int change(int idx)
{
    string tmp1 = arr[idx];
    string tmp2 = arr2[idx];

    if(tmp1==" "){
        tmp1 = "0000000";
    }
    else if(tmp1=="0"){
        tmp1 = "1110111";
    }
    else if(tmp1=="1"){
        tmp1 = "0010010";
    }
    else if(tmp1=="2"){
        tmp1 = "1011101";
    }
    else if(tmp1=="3"){
        tmp1 = "1011011";
    }
    else if(tmp1=="4"){
        tmp1 = "0111010";
    }
    else if(tmp1=="5"){
        tmp1 = "1101011";
    }
    else if(tmp1=="6"){
        tmp1 = "1101111";
    }
    else if(tmp1=="7"){
        tmp1 = "1110010";
    }
    else if(tmp1=="8"){
        tmp1 = "1111111";
    }
    else if(tmp1=="9"){
        tmp1 = "1111011";
    }
    
    if(tmp2==" "){
        tmp2 = "0000000";
    }
    else if(tmp2=="0"){
        tmp2 = "1110111";
    }
    else if(tmp2=="1"){
        tmp2 = "0010010";
    }
    else if(tmp2=="2"){
        tmp2 = "1011101";
    }
    else if(tmp2=="3"){
        tmp2 = "1011011";
    }
    else if(tmp2=="4"){
        tmp2 = "0111010";
    }
    else if(tmp2=="5"){
        tmp2 = "1101011";
    }
    else if(tmp2=="6"){
        tmp2 = "1101111";
    }
    else if(tmp2=="7"){
        tmp2 = "1110010";
    }
    else if(tmp2=="8"){
        tmp2 = "1111111";
    }
    else if(tmp2=="9"){
        tmp2 = "1111011";
    }

    int ans = 0;
    for(int i=0; i<7; i++){
        if(tmp1[i]!=tmp2[i]){
            ans++;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        string a,b; cin >> a >> b;

        int i;
        int idx = 0;
        for(i=a.size()-1; i>=0; i--){
            //cout << a[i];
            arr[idx++]=a[i];
        }

        for(i=a.size(); i<5; i++){
            arr[i]=" ";
        }
    

        idx = 0;
        for(int i=b.size()-1; i>=0; i--){
            //cout << b[i];
            arr2[idx++]=b[i];
        }
        for(int i=b.size(); i<5; i++){
            arr2[i]=" ";
        }

        int ans = 0;
        for(int i=0; i<5; i++){
            ans += change(i);
        }
        cout << ans << "\n";
    }

    return 0;
}