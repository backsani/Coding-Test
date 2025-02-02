#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(string str : skill_trees)
    {
        bool can = true;
        int i = 0;
        for(char ch : str)
        {
            int it = skill.find(ch);
            if(it != string::npos)
            {
                if(i == it)
                {
                    i++;
                }
                else
                {
                    can = false;
                    break;
                }
            }
        }
        if(can)
            answer++;
    }
    return answer;
}