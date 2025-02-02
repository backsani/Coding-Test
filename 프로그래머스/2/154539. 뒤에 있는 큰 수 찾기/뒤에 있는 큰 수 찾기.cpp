#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    stack<int> s;
    vector<int> answer(numbers.size(), -1);
    
    for(int i = numbers.size() - 1; i >= 0; i--)
    {
        if(!s.empty() && numbers[i] >= s.top())
        {
            s.pop();
            i++;
            continue;
        }
        
        if(!s.empty() && numbers[i] < s.top())
        {
            answer[i] = s.top();
        }
            
        s.push(numbers[i]);
    }
    
    return answer;
}