#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Offer{
    int size; // 몇번 째 고객인지. 
    int payment;
    int buyer;
};

struct Scenario {
    int money;
    int idx;
    int result = -1;
};

bool offerCmp(const Offer &a, const Offer &b)
{
    return a.size < b.size;
}

bool scenarioCmp(const Scenario &a, const Scenario &b)
{
    return a.money < b.money;
}

bool resultCmp(const Scenario &a, const Scenario &b)
{
    return a.idx < b.idx;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    vector<Offer> offers;

    for(int i=1; i<=N; i++){
        int a; cin >> a;
        while(a--){
            int x,y;
            cin >> x >> y;
            offers.push_back({x,y,i});
        }
    }

    int M; cin >> M;
    vector<Scenario> scenarios(M);
    for(int i=0; i<M; i++){
        int a; cin >> a;
        scenarios[i].money = a;
        scenarios[i].idx = i;
    }

    sort(offers.begin(), offers.end(), offerCmp);
    sort(scenarios.begin(), scenarios.end(), scenarioCmp);

    vector<int> prevPay(N+1,0);
    int total = 0;
    int s_index = 0;

    for(auto &offer : offers){
        int buyer = offer.buyer;
        int payment = offer.payment;

        while(payment > prevPay[buyer]){ // 기존에 지불했지만 더 많이지불 가능느
            total += (payment - prevPay[buyer]);
            prevPay[buyer] = payment;
        }

        while(s_index < M && scenarios[s_index].money <= total){ // 시나리오 돈보다 total은 커야함.
            scenarios[s_index].result = offer.size;
            s_index++;
        }
    }

    sort(scenarios.begin(), scenarios.end(), resultCmp);
    for(auto &a : scenarios){
        cout << a.result << " ";
    }
    cout << "\n";

    return 0;
}