#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 1;
    
    vector<stack<int>> v(w, stack<int>());
    bool right = true;
    int index = 0;
    
    for(int i = 1; i <= n; i++)
    {
        if(index >= w)
        {
            right = false;
            index--;
        }
        else if(index < 0)
        {
            right = true;
            index++;
        }
        
        v[index].push(i);
        
        index += right ? 1 : -1;
    }
    
    int floor = ceil((float)num / w);
    index = floor % 2 != 0 ? num % w - 1 : (w - (num % w)) % w;
    if(index == -1)
        index = w - 1;
    
    while(v[index].size() != 0)
    {
        if(v[index].top() == num)
            return answer;
        
        v[index].pop();
        answer++;
    }
    
    return -1;
}