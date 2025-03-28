#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(string s) {
    unordered_map<int, string> m;
    
    m[0] = "zero"; m[1] = "one"; m[2] = "two"; m[3] = "three"; m[4] = "four";
    m[5] = "five"; m[6] = "six"; m[7] = "seven"; m[8] = "eight"; m[9] = "nine";
    
    int answer = 0;

    for(int i = 0; i < 10; i++)
    {
        int it = 0;
        while((it = s.find(m[i])) != string::npos)
        {
            s.replace(it, m[i].length(), to_string(i));
        }
    }
    
    
    return stoi(s);
}