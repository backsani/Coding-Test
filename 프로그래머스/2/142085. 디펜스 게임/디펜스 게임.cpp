#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = -1;
    
    auto cmp = [](pair<int, int> p1, pair<int, int> p2){
        return p1.first < p2.first;
    };
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    
    int round = 0;
    int sum = 0;
    
    while(true)
    {
        while(sum <= n)
        {
            if(round >= enemy.size())
            {
                return enemy.size();
            }
            pq.push(make_pair(enemy[round], round));
            sum += enemy[round];
            round++;
        }
        
        if(k > 0)
        {
            auto temp = pq.top();
            sum -= temp.first;
            pq.pop();
            k--;
        }
        else
        {
            if(sum == n)
                return round;
            else
                return round - 1;
        }
    }
    
    return answer;
}