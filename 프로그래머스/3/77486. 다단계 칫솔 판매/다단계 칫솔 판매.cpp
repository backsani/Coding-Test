#include <string>
#include <vector>
#include <map>

using namespace std;

void sell(map<string, string>& referrals, map<string, int>& profit, string seller, int money)
{
    int charge = money / 10;
    int sellerMoney = money - charge;
    
    if(referrals.find(seller) != referrals.end() && charge > 0)
    {
        profit[seller] = sellerMoney + profit[seller];
        sell(referrals, profit, referrals[seller], charge);
    }
    else
    {
        profit[seller] = money + profit[seller];
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    // 추천인, 피추천인
    map<string, string> referrals;
    // 멤버, 수익금
    map<string, int> profit;
    // 민호 초기화
    profit["-"] = 0;
    
    for(int i = 0; i < enroll.size(); i++)
    {
        referrals[enroll[i]] = referral[i];
        profit[enroll[i]] = 0;
    }
    
    for(int i = 0; i < seller.size(); i++)
    {
        sell(referrals, profit, seller[i], amount[i] * 100);
    }
    
    for(string str : enroll)
    {
        answer.push_back(profit[str]);
    }
    
    return answer;
}