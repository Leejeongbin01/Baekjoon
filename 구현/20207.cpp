// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cstring>
// using namespace std;

// bool cmp(pair<int, int> &a, pair<int, int> &b)
// {
//     if(a.first == b.first){
//         return a.second > b.second;
//     }
    
//     return a.first < b.first;
// }

// int main()
// {
//     int N; cin >> N;
//     vector<pair<int, int>> v;
//     int arr[1050][1050];
//     memset(arr, 0, sizeof(arr));
//     for(int i=0; i<N; i++){
//         int a,b; cin >> a>> b;
//         v.push_back({a,b});
//     }
//     sort(v.begin(), v.end(), cmp);

//     for(int i=0; i<N; i++){
//         //int a,b; cin >> a >> b;
//         int a=v[i].first;
//         int b=v[i].second;
//         int line = 1;
//         while(1){
//             bool flag = true;
//             for(int j=a; j<=b; j++){
//                 if(arr[line][j]!=0){
//                     flag = false;
//                 }
//             }
//             if(flag){
//                 break;
//             }
//             line++;
            
//         }

//         //cout << a << " " << b << " " << line << endl;
//         for(int j=a; j<=b; j++){
//             arr[line][j] = 1;
//         }
//     }
    
//     /*
//     for(int i=0; i<5; i++){
//         for(int j=0; j<15; j++){
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
//     */

//     int ans = 0;
//     int width = 0;
//     int height = 0;
//     for(int j=1; j<=500; j++){
//         bool check=false;
//         int h=0;
//         for(int i=1; i<=500; i++){
//             if(arr[i][j]){
//                 check = true;
//                 h = max(h,i);
//             }
//         }

//         if(check){
//             width++;
//             height = max(height,h);
//         }
//         else{
//             if(width > 0){
//                 ans += width * height;
//                 width = 0;
//                 height = 0;
//             }
//         }
//     }

//     if(width > 0){
//         ans += width * height;
//     }

//     cout << ans << endl;
//     return 0;
// }

