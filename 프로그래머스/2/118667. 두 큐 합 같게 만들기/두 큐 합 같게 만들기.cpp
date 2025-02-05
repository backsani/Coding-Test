#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> q1;
    queue<int> q2;
    long sum1 = 0;
    long sum2 = 0;
    
    for(int i =0; i < queue1.size(); i++)
    {
        q1.push(queue1[i]);
        q2.push(queue2[i]);
        
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    
    if((sum1 + sum2) % 2 != 0)
        return -1;
    
    while(!(q1.size() < 1 || q2.size() < 1))
    {
        if(answer / 2 > q1.size() + q2.size())
            return -1;
        
        if(sum1 > sum2)
        {
            sum1 -= q1.front();
            sum2 += q1.front();
            q2.push(q1.front());
            q1.pop();
            answer++;
        }
        else if(sum1 < sum2)
        {
            sum1 += q2.front();
            sum2 -= q2.front();
            q1.push(q2.front());
            q2.pop();
            answer++;
        }
        else if(sum1 == sum2)
            return answer;
    }
    
    if(sum1 == sum2)
        return answer;
    
    return -1;
}