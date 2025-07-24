#include <iostream>
#include <stack>
#include <vector>
#include <set>
using namespace std;

int main()
{
    string str; cin >> str;
    vector<pair<int,int>> v;
    stack<int> stack;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='('){
            stack.push(i);
        }
        else if(str[i]==')'){
            int tmp = stack.top();
            stack.pop();
            v.push_back({tmp,i});
        }
    }    
    /*
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
    */
    
    // 2의 n승-1
    // 001 - 1
    // 010 - 2
    // 011 - 1,2
    // 100 - 4
    // 101 - 1,4
    // 110 - 2,4
    // 111 - 1,2,4
    set<string> result;
    for(int i=1; i<(1<<v.size()); i++){
        vector<bool> remove(str.size(), false);
        for(int j=0; j<v.size(); j++){
            if(i & (1<<j)){
                remove[v[j].first]=true;
                remove[v[j].second] = true;
            }
        }

        string res="";
        for(int j=0; j<str.size(); j++){
            if(remove[j]==false){
                res+=str[j];
            }
        }

        result.insert(res);
    }
    
    for(auto it : result){
        cout << it << endl;
    }
    return 0;
}