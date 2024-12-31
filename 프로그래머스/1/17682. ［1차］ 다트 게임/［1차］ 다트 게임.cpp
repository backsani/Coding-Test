#include <string>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<pair<int, string>> dart;
    
    bool endP = false;
    string num = "";
    string op = "";
    int score = 0;
    
    for(char ch : dartResult)
    {
        if((ch >= '0' && ch <= '9'))
        {
            if(num != "" && op != "")
            {
                score = stoi(num);
                dart.push_back(make_pair(score, op));
                
                score = 0;
                num = "";
                op = "";
                num += ch;
            }
            else if(op == "")
            {
                num += ch;
            }
            
        }
        else if(ch == 'S' || ch == 'D' || ch == 'T')
        {
            op += ch;
        }
        else if(ch == '*' || ch == '#')
        {
            op += ch;
        }
    }
    score = stoi(num);
    dart.push_back(make_pair(score, op));
    
    vector<int> result(dart.size(), 0);
    
    for(int i = 0; i < dart.size(); i++)
    {
        result[i] = dart[i].first;
        
        if(dart[i].second[0] == 'S')
        {
            
        }
        else if(dart[i].second[0] == 'D')
        {
            result[i] = result[i] * result[i];
        }
        else if(dart[i].second[0] == 'T')
        {
            result[i] = result[i] * result[i] * result[i];
        }
        
        
        if(dart[i].second[1] == '*')
        {
            if(i != 0)
                result[i - 1] *= 2;
            result[i] *= 2;

        }
        else if(dart[i].second[1] == '#')
        {
            result[i] *= -1;
        }
        
    }
    
    for(int i : result)
    {
        answer += i;
    }
    
    return answer;
}