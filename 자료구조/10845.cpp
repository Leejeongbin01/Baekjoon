#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> v;
    while(N--){
        string str; cin >> str;
        if(str=="push"){
            int a; cin >> a;
            v.push_back(a);
        }
        else if(str=="pop"){
            if(v.size()==0){
                cout << -1 << endl;
            }
            else{
                cout << v.front() << endl;
                vector<int> tmp;
                for(int i=1; i<v.size(); i++){
                    tmp.push_back(v[i]);
                }
                while(!v.empty()){
                    v.pop_back();
                }

                for(int i=0; i<tmp.size(); i++){
                    v.push_back(tmp[i]);
                }
            }
        }
        else if(str=="size"){
            cout << v.size() << endl;
        }
        else if(str=="empty"){
            if(v.size()==0){
                cout << 1 << endl;
            }   
            else{
                cout << 0 << endl;
            }
        }
        else if(str=="front"){
            if(v.size()==0){
                cout << -1 << endl;
            }   
            else{
                cout << v.front() << endl;
            }
        }
        else if(str=="back"){
            if(v.size()==0){
                cout << -1 << endl;
            }   
            else{
                cout << v.back() << endl;
            }
        }
    }

    return 0;
}