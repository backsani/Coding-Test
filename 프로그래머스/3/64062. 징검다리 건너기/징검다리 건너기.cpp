#include <string>
#include <vector>
#include <queue>
#include <map>
#include <climits>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = INT_MAX;
    
    queue<int> q;
    map<int, int> m;
    
    for(int i : stones)
    {
        q.push(i);
        m[i]++;
        
        if(q.size() >= k)
        {            
            answer = min(m.rbegin()->first, answer);
            
            int n = q.front();
            m[n]--;
            q.pop();
            
            if(m[n] == 0)
                m.erase(n);
        }
    }
    
    return answer;
}