#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    int N; cin >> N;
    int score = 0;
    int team1 = 0, team2 = 0;
    int team1_time = 0,  team2_time = 0;
    int prev = 0;
    for(int i=0; i<N; i++){
        int team; cin >> team;
        string str; cin >> str;
        
        string min = str.substr(0,2);
        string sec = str.substr(3,2);
        int time = stoi(min) * 60 + stoi(sec);
        //cout << "time : " << time << endl;

        if(team1 > team2){
            team1_time = team1_time + time - prev;
        }
        else if(team1 < team2){
            team2_time = team2_time + time - prev;
        }

        if(team == 1) team1++;
        else team2++;
        prev = time;
    }

    if(team1 > team2){
        team1_time = team1_time + (48*60)-prev;
    }
    else if(team1 < team2){
        team2_time = team2_time + (48*60)-prev;
    }

    cout << setfill('0') << setw(2) << team1_time / 60 << ":" 
         << setfill('0') << setw(2) << team1_time % 60 << endl;

    cout << setfill('0') << setw(2) << team2_time / 60 << ":" 
         << setfill('0') << setw(2) << team2_time % 60 << endl;
    return 0;
}