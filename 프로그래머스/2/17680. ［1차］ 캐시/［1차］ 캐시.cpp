#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> temp;
    
    if(cacheSize == 0)
        return cities.size() * 5;
    
    for(string city : cities)
    {
        
        string str = "";
        //모든 문자 대문자로 변경
        for(char ch : city)
        {
            str += toupper(ch);
        }
            
        
        auto it = find(temp.begin(), temp.end(), str);
        if(it != temp.end())
        {
            temp.erase(it);
            temp.push_back(str);
            answer += 1;
        }
        else
        {
            temp.push_back(str);
            answer += 5;
            
            if(temp.size() > cacheSize)
            {
                temp.pop_front();
            }
        }
        
    }
    
    return answer;
}