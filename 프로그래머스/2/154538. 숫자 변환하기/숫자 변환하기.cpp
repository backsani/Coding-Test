#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    
    //int : 현재 연산 값, int : 연산 횟수
    queue<pair<int, int>> q;
    q.push(make_pair(x, 0));
    set<int> s;
    s.insert(x);
    
    while(!q.empty())
    {
        int current = q.front().first;
        int step = q.front().second;
        
        q.pop();
        
        if(current == y)
            return step;
        
        int value[3] = {current + n, current * 2, current * 3};
        
        for(int i : value)
        {
            if(i <= y && s.find(i) == s.end())
            {
                q.push(make_pair(i, step + 1));
                s.insert(i);
            }
        }
        
    }
    
    return -1;
}