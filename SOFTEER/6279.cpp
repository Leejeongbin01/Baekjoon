#include <iostream>
using namespace std;

int N,K;
string str;
// H = 부품
// P = 로봇
bool visit[20001];

int main()
{
    cin >> N >> K;
    cin >> str;
    int ans = 0;

    for(int i=0; i<str.size(); i++){
        if(str[i]=='H') continue;

        if(i-K < 0){
            for(int j=0; j<=i+K;  j++){
                if(str[j]=='H' && visit[j]==false){
                    ans++;
                    visit[j]=true;
                    break;
                }
            }
        }
        else{
            for(int j=i-K; j<=i+K; j++){
                if(str[j]=='H' && visit[j]==false){
                    ans++;
                    visit[j]=true;
                    break;
                }
            }
        }
        cout << i << " " << ans << "\n";
    }

    cout << ans << "\n";
    return 0;
}