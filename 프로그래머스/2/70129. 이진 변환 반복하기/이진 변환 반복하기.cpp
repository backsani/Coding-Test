#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2,0);
    
    
    while(s.size() != 1)
    {
        int zeroCount = 0;
        for(char ch : s)
        {
            if(ch == '0')
                zeroCount++;
        }
        
        int i = s.size() - zeroCount;
        s = "";
        
        while(i > 0)
        {
            s = (i % 2 == 0 ? "0" : "1") + s;
            i /= 2;
        }
        
        answer[0]++;
        answer[1] += zeroCount;
    }
    
    return answer;
}