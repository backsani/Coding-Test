#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string before, string after) {
    int answer = 0;
    unordered_map<char, int> m;
    
    for(char ch : before)
    {
        m[ch]++;
    }
    
    for(char ch : after)
    {
        if(--m[ch] == 0)
        {
            m.erase(ch);
        }
        
    }
    
    return m.empty() ? 1 : 0;
}