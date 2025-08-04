#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

// 루돌프는 6번씩 경기
// (1,2),(1,3),(1,4),(2,3),(2,4),(3,4)
// 이길, 질 , 비길 확률
// 1번 루돌프가 최종적으로 전체 순위에서 2등 이내(1,2등)들어갈 확률을 구해라.

int F[4];
double result;

double getProb(int a, int b, char r) {
    if (r == 'w') return (4.0 * a) / (5.0 * (a + b));
    if (r == 'l') return (4.0 * b) / (5.0 * (a + b));
    return 1.0 / 5.0;
}

vector<pair<int,int>> matches = {
    {0,1}, {0,2}, {0,3},
    {1,2}, {1,3}, {2,3}
};

pair<int, int> getScore(char r) {
    if (r == 'w') return {3, 0};
    if (r == 'l') return {0, 3};
    return {1, 1};
}

void dfs(int depth, vector<char>& path)
{
    if(depth==6){
        vector<int> score(4,0);
        double prob = 1.0;

        for(int i=0; i<6; i++){
            int a = matches[i].first;
            int b = matches[i].second;
            char r = path[i];

            prob *= getProb(F[a], F[b], r);
            auto [sa,sb] = getScore(r);
            score[a] += sa;
            score[b] += sb;
        }

        vector<pair<int,int>> ranking;
        for(int i=0; i<4; i++){
            ranking.push_back({score[i],-i});
        }
        sort(ranking.rbegin(), ranking.rend());

        if(-ranking[0].second == 0 || -ranking[1].second == 0){
            result += prob;
        }

        return;
    }

    for(char c : {'w','d','l'}){
        path.push_back(c);
        dfs(depth+1, path);
        path.pop_back();
    }
}

int main()
{
    for(int i=0; i<4; i++){
        cin >> F[i];
    }

    vector<char> path;
    dfs(0, path);
    cout << fixed << setprecision(3) << result *100.0 << "\n";
    return 0;
}