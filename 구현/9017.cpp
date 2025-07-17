#include <iostream>
using namespace std;

int main()
{
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        int team[1001] = {0};
        int save[1001];
        int score[1001];
        int team_score[1001] = {0};
        int max_num = 0;
        int team5[1001] = {0};
        for(int i=1; i<=N; i++){
            int a; cin >> a;
            team[a]++;
            save[i]=a;
            score[i]=i;
            if(max_num < a) max_num = a;
        }

        int check = 0;
        for(int i=1; i<=N; i++){
            int tmp = save[i];
            if(team[tmp] < 6){
                check++;
                score[i] = 0;
                team_score[tmp] = 0;
                continue;
            }

            score[i] = score[i] - check;
            team_score[tmp] += score[i];
        }

        /*
        for(int i=1; i<=N; i++){
            cout << score[i] << " ";
        }
        cout << endl;
        */
        
        /*
        for(int i=1; i<=max_num; i++){
            cout << team_score[i] << " ";
        }
        cout << endl;
        */

        int tmparr[1001] = {0};
        int total[1001] = {0};
        for(int i=1; i<=N; i++){
            int tmp = save[i];
            tmparr[tmp]++;
            if(tmparr[tmp]==5){
                team5[tmp]=score[i];
            }

            if(tmparr[tmp] <= 4){
                total[tmp] += score[i];
            }
        }

        /*
        for(int i=1; i<=max_num; i++){
            cout << total[i] << " ";
        }
        cout << endl;
        */

        int max_score = 1e9;
        int max_idx = 0;
        for(int i=1; i<=max_num; i++){
            if(total[i] < max_score && total[i] != 0){
                max_score = total[i];
                max_idx = i;
            }
        }
        //cout << max_score << " " << max_idx << endl;

        int check1 = 0;
        for(int i=1; i<=max_num; i++){
            if(total[i]==max_score){
                check1++;
            }
        }

        //cout << "check1 : " << check1 << endl;
        if(check1 >= 2){
            int idx5 = 0;
            int max5 = 1e9;
            for(int i=1; i<=max_num; i++){
                if(total[i]==max_score){
                    if(max5 > team5[i]){
                        max5 = team5[i];
                        idx5 = i;
                    }
                }
            }

            cout << idx5 << endl;
        }
        else{
            cout << max_idx << endl;
        }
    }

    return 0;
}