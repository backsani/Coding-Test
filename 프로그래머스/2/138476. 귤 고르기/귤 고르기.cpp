#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> m;
    
    for(int i : tangerine)
    {
        m[i]++;
    }
    
    vector<pair<int, int>> p(m.begin(), m.end());
    
    sort(p.begin(), p.end(), [](const pair<int, int> p1, const pair<int, int> p2){
         if(p1.second != p2.second)
         {
             return p1.second > p2.second;
         }
         return p1.first < p2.first;
         });
    
    for(pair<int, int> num : p)
    {
        k -= num.second;
        answer++;
        if(k <= 0)
            break;
    }
    
    return answer;
}