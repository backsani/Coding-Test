#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = new_id;
    
    for(auto it = answer.begin(); it != answer.end();)
    {
        if(isupper(*it))
        {
            *it = tolower(*it);
            
        }
        if(!(islower(*it) || isdigit(*it) || *it == '-' || *it == '_' || *it == '.'))
        {
            answer.erase(it);
            continue;
        }
        if(*it == '.' && (*(it - 1) == '.' && it != answer.begin()))
        {
            answer.erase(it);
            continue;
        }
        
        ++it;
    }
    
    if(!answer.empty() && answer.front() == '.')
    {
        answer.erase(answer.begin());
    }
    if(!answer.empty() && answer.back() == '.')
    {
        answer.erase(answer.size() - 1);
    }
    
    if(answer.empty())
    {
        answer += 'a';
    }
    if(answer.length() > 15)
    {
        string temp = answer.substr(0, 15);
        answer = temp;
        if(answer.back() == '.')
            answer.erase(answer.size() - 1);
    }
    
    while(answer.size() <= 2)
    {
        answer += answer.back();
    }
    
    return answer;
}