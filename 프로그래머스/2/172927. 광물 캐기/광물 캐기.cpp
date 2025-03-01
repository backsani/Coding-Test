#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    vector<int> v;
    
    int i = 0;
    int sum = 0;
    
    for(string str : minerals)
    {
        i++;
        
        if(str == "diamond")
            sum += 100;
        else if(str == "iron")
            sum += 10;
        else if(str == "stone")
            sum += 1;
        
        if(i == 5)
        {
            v.push_back(sum);
            sum = 0;
            i = 0;
            
            if(v.size() == picks[0] + picks[1] + picks[2])
                break;
        }
    }
    
    if(sum != 0)
        v.push_back(sum);
    
    sort(v.rbegin(), v.rend());
    
    for(int i : v)
    {
        int pick = 1;
        if(picks[0]-- <= 0)
        {
            pick = 2;
            if(picks[1]-- <= 0)
            {
                pick = 3;
                if(picks[2]-- <= 0)
                    return answer;
            }
        }
        
        while(i > 0)
        {
            if(i >= 100)
            {
                i -= 100;
                if(pick == 1)
                    answer += 1;
                else if(pick == 2)
                    answer += 5;
                else if(pick == 3)
                    answer += 25;
            }
            else if(i >= 10)
            {
                i -= 10;
                if(pick == 1)
                    answer += 1;
                else if(pick == 2)
                    answer += 1;
                else if(pick == 3)
                    answer += 5;
            }
            else
            {
                i -= 1;
                answer += 1;
            }
        }
    }
    
    return answer;
}