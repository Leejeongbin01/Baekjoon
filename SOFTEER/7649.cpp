#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 1. 트리 구조를 만들어야함. 
// -> 트리 구조의 간선 가중치에는 문자가 있어야함. 
// 2. DFS로 출력되는 문자열을 저장하고
// 3. 저장된 문자열의 최대 행복지수를 구하면 될듯

int N,M; // 정점의 개수, 문자열의 길이
string strHappy; // 행복해하는 문자열
vector<pair<int,int>> tree[5003]; // 갈 노드와 노선의 가중치
vector<string> strList;
bool visit[5003];

int lcs(string &a, string &b)
{
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}


void DFS(string str, int x)
{
    /*
    if(str.size() == M){
        strList.push_back(str);
        return;
    }
    */

    visit[x]=true;
    for(int i=0; i<tree[x].size(); i++){
        int tmp = tree[x][i].first;
        int tmpChar = tree[x][i].second;
        if(visit[tmp]==false){
            visit[tmp]=true;
            string strTmp = str;
            strTmp += tmpChar;
            DFS(strTmp, tmp);
            visit[tmp]=false;
        }
    }

    strList.push_back(str);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. input
    cin >> N >> M;
    cin >> strHappy;
    for(int i=0; i<N-1; i++){
        int a, b;
        char c;
        cin >> a >> b >> c;
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }

    // 2. DFS
    DFS("",1);

    // 3. check
    /*
    for(int i=0; i<strList.size(); i++){
        cout << strList[i] << "\n";
    }
    */

    // 4. answer(org)
    /*
    int ans = 0;
    int tmpCnt = 0;
    for(int i=0; i<strList.size(); i++){
        string strTmp = strList[i];
        tmpCnt = 0;
        int tmpIdx = 0;
        for(int j=0; j<strHappy.size(); j++){
            if(strTmp[tmpIdx]==strHappy[j]){
                tmpIdx++;
                tmpCnt++;
            }
            else{
                // tmpCnt = 0;
            }
        }

        ans = max(ans, tmpCnt);
    }
    cout << ans << "\n";
    return 0;
    */

    // 4. LCS
    int ans = 0;
    for(int i=0; i<strList.size(); i++){
        ans = max(ans, lcs(strList[i], strHappy));
    }

    cout << ans << "\n";
    return 0;
}