#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(string numbers) {
    long long answer = 0;
    string temp = "";
    
    map<string, int> m;
    m["one"] = 1; m["two"] = 2; m["three"] = 3; m["four"] = 4; m["five"] = 5; m["six"] = 6; m["seven"] = 7; m["eight"] = 8; m["nine"] = 9; m["zero"] = 0; 
    
    for(char ch : numbers)
    {
        temp += ch;
        if(m.find(temp) != m.end())
        {
            answer = answer * 10 + m[temp];
            temp = "";
        }
    }
    
    return answer;
}