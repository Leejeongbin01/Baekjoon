#include <iostream>
#include <cstring>
using namespace std;

string msg, key;
char arr[6][6];
bool visit[26];
int idx=0;
string str[501];
int locX, locY;

// easy, buf 복잡

void first()
{
    int x=1, y=1;
    for(int i=0; i<key.size(); i++){
        char tmp = key[i];
        //cout << tmp << endl;
        if(visit[tmp-'A']==false){
            arr[x][y] = tmp;
            visit[tmp-'A']=true;
            y++;

            if(y==6){
                y=1;
                x++;
            }
            // cout << arr[x][y] << " " << x << " " << y<<endl;
        }
    }

    // cout << x << " " << y << "\n";
    for(char c='A'; c <='Z'; c++){
        if(c=='J') continue;
        if(visit[c-'A']==false){
            arr[x][y]=c;
            y++;
            if(y==6){
                y=1;
                x++;
            }
        }
    }

    cout << "\n";
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void second()
{
    string copyMsg = msg;
    copyMsg += "J";
    for(int i=0; i<copyMsg.size(); i++){
        string tmpStr = "";
        tmpStr += copyMsg[i];
        tmpStr += copyMsg[i+1];
        //cout << tmpStr << endl;

        if(tmpStr=="XX"){
            tmpStr="XQ";
        }
        else if(tmpStr[0]==tmpStr[1]){
            tmpStr = tmpStr[0];
            tmpStr += "X";
        }
        else if(i==msg.size()-1 && tmpStr[1]=='J'){
            //cout << "here\n";
            tmpStr[1]='X';
        }
        else{
            i++;
        }

        str[idx]=tmpStr;
        idx++;
        //cout << tmpStr << "\n";
    }

    for(int i=0; i<idx-1; i++){
        cout << str[i] << "\n";
    }
    cout << "\n";
}

bool isSameRow(string str)
{
    char fir = str[0];
    char sec = str[1];
    int dou=0;
    for(int i=1; i<=5; i++){
        dou = 0;
        for(int j=1; j<=5; j++){
            if(arr[i][j]==fir || arr[i][j]==sec){
                dou++;
                if(dou==2) {
                    locX = i;
                    return true;
                }
            }
        }
    }

    return false;
}

bool isSameCol(string str)
{
    char fir = str[0];
    char sec = str[1];
    int dou=0;
    for(int i=1; i<=5; i++){
        dou = 0;
        for(int j=1; j<=5; j++){
            if(arr[j][i]==fir || arr[j][i]==sec){
                dou++;
                if(dou==2) {
                    locY = i;
                    return true;
                }
            }
        }
    }

    return false;
}

string seekRow(string str, int x)
{
    char fir = str[0];
    char sec = str[1];
    char newFir;
    char newSec;
    for(int i=1; i<=5; i++){
        if(arr[x][i]==fir){
            if(i==5){
                newFir = arr[x][1];   
            }
            else{
                newFir = arr[x][i+1];
            }
        }
        else if(arr[x][i]==sec){
            if(i==5){
                newSec = arr[x][1];   
            }
            else{
                newSec = arr[x][i+1];
            }
        }
    }

    string ret ="";
    ret += newFir;
    ret += newSec;
    return ret;
}

string seekCol(string str, int y)
{
    char fir = str[0];
    char sec = str[1];
    char newFir;
    char newSec;
    for(int i=1; i<=5; i++){
        if(arr[i][y]==fir){
            if(i==5){
                newFir = arr[1][y];   
            }
            else{
                newFir = arr[i+1][y];
            }
        }
        else if(arr[i][y]==sec){
            if(i==5){
                newSec = arr[1][y];   
            }
            else{
                newSec = arr[i+1][y];
            }
        }
    }

    string ret ="";
    ret += newFir;
    ret += newSec;
    return ret;
}

string seekRowCol(string str)
{
    char fir = str[0];
    char sec = str[1];
    char newFir;
    char newSec;

    int firX, firY, secX, secY;
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            if(arr[i][j]==fir){
                firX=i;
                firY=j;
            }
            else if(arr[i][j]==sec){
                secX=i;
                secY=j;
            }
        }
    }

    newFir = arr[firX][secY];
    newSec = arr[secX][firY];    

    string ret ="";
    ret += newFir;
    ret += newSec;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> msg >> key;

    first();
    second();

    cout << "main\n";
    string ans = "";
    for(int i=0; i<idx-1; i++){
        string tmpStr = str[i];
        // cout << tmpStr << "\n";
        locX = -1, locY= -1;
        if(isSameRow(tmpStr)){
            string shiftStr = seekRow(tmpStr, locX);
            ans += shiftStr[0];
            ans += shiftStr[1];
            // cout << "sameRow : " << tmpStr << " " << shiftStr << "\n";
        }
        else if(isSameCol(tmpStr)){
            string shiftStr = seekCol(tmpStr, locY);
            ans += shiftStr[0];
            ans += shiftStr[1];
            //cout << "sameCol : " << tmpStr << " " << shiftStr << "\n";
        }
        else{
            string shiftStr = seekRowCol(tmpStr);
            ans += shiftStr[0];
            ans += shiftStr[1];
            //cout << "Else : " << tmpStr << " " << shiftStr << "\n";
        }
    }

    cout << ans << "\n";
    return 0;
}