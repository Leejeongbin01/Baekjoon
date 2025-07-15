#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T; cin >> T;
    while(T--){
        string W; cin >> W;
        int K; cin >> K;
        vector<int> alpha[26];
        for(int i=0; i<W.size(); i++){
            alpha[W[i]-'a'].push_back(i);
        }
        
        int minLen = 99999999;
        int maxLen = -1;
        for(int i=0; i<26; i++){
            if(alpha[i].size() < K) continue;

            for(int j=0; j<=alpha[i].size()-K; j++){
                int len = alpha[i][j+K-1] - alpha[i][j] + 1;
                minLen = min(minLen, len);
                maxLen = max(maxLen, len);
            }
        }

        if(maxLen == -1) cout << -1 << endl;
        else cout << minLen << " " << maxLen << endl;
    }

    return 0;
}