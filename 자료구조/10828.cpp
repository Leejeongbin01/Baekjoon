#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> v;
    while(N--){
        string str; cin >> str;
        int a;
        if(str == "push"){
            cin >> a;
            v.push_back(a);
        }
        else if(str == "pop"){
            if(v.size()==0){
                cout << -1 << endl;
            }
            else{
                cout << v.back() << endl;
                v.pop_back();
            }
        }
        else if(str == "size"){
            cout << v.size() << endl;   
        }
        else if(str == "empty"){
           if(v.size()==0){
                cout << 1 << endl;
           } 
           else{
                cout << 0 << endl;
           }
        }
        else if(str == "top"){
           if(v.size()!=0){
            cout << v.back() << endl;
           } 
           else{
            cout << -1 << endl;
           }
        }
    }

    return 0;
}