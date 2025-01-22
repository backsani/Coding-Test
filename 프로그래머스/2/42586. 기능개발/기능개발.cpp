#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> day;
    
    for(int i = 0; i < progresses.size(); i++)
    {
        day.push_back(ceil((100.0 - progresses[i]) / speeds[i]));
    }
    
    int time = -1;

    for(int i : day)
    {
        if(time < i)
        {
            time = i;
            answer.push_back(1);
        }
        else
        {
            int n = answer.back();
            n++;
            answer.pop_back();
            answer.push_back(n);
        }
    }
    
    return answer;
}