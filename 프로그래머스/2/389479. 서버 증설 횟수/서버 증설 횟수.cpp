#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    // 증설된 서버 수 / 유지된 시간
    queue<pair<int, int>> q;
    
    int currentServer = 0;
    
    for(int i : players)
    {
        if(i >= m * currentServer + m)
        {
            int n = ceil((float)(i - m + 1) / m);
            
            if(n > 0)
            {
                q.push({n - currentServer, 0});
                answer += n- currentServer;
                currentServer += n - currentServer;
            }
        }
        
        queue<pair<int, int>> temp;
        
        while(!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            
            p.second += 1;
            
            if(p.second >= k)
            {
                currentServer -= p.first;
                continue;
            }
            temp.push(p);
        }
        
        q = temp;
    }
    
    return answer;
}