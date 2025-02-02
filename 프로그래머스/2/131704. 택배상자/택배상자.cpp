#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> subBelt;
    
    int num = 1;
    for(int i = 0; i < order.size(); i++)
    {
        while(order[i] > num)
        {
            subBelt.push(num);
            num++;
        }
        if(num == order[i])
        {
            answer++;
            num++;
            continue;
        }
        if(order[i] < num)
        {
            if(subBelt.top() == order[i])
            {
                answer++;
                subBelt.pop();
            }
            else
                break;
        }

    }
    
    return answer;
}