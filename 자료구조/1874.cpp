#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; cin >> N;
    stack<int> stack;
    vector<char> v;
    int x=1;
    for(int i=0; i<N; i++){
        int a; cin >> a;

        while(x<=a){
            if(x <= a){
                stack.push(x);
                x++;
                v.push_back('+');
            }
        }

        if(stack.top()==a){
            stack.pop();
            v.push_back('-');
        }
        else{
            cout << "NO";
            return 0;
        }
    }

    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }
    return 0;
}