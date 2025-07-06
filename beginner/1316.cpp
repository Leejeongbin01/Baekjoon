#include <iostream>
using namespace std;

int main()
{
    int N; cin >> N;

    int sum = 0;
    for(int i=0; i<N; i++){
        int cnt = 0;
        int arr[129]={0};
        string str; cin >> str;

        for(int j=0; j<str.size(); j++){
            if(arr[str[j]-'A']==0){
                arr[str[j]-'A']=1;
            }
            else{
                if(j>=1 && str[j-1]==str[j]){
                    continue;
                }
                else{
                    cnt++;
                }
            }
        }

        if(cnt==0){
            sum++;
        }
    }

    cout << sum << endl;
    return 0;
}