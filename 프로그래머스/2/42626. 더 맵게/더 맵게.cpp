#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i : scoville)
    {
        q.push(i);
    }
    
    
    while(q.top() < K)
    {
        if(q.size() < 2)
            return -1;
        
        int k1 = q.top();
        q.pop();
        int k2 = q.top();
        q.pop();
        q.push(k1 + (k2 * 2));
        answer++;
    }
    
    return answer;
}