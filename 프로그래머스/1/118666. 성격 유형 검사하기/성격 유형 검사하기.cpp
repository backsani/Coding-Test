#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char,int> m;
    m['R'] = 0; m['T'] = 0; m['C'] = 0; m['F'] = 0; m['J'] = 0; m['M'] = 0; m['A'] = 0; m['N'] = 0; 
    
    for(int i = 0; i < survey.size(); i++)
    {
        string str = survey[i];
        if(choices[i] > 4)
        {
            m[str[1]] += choices[i] - 4;
        }
        else if(choices[i] < 4)
        {
            m[str[0]] += 4 - choices[i];
        }
    }
    
    answer += m['R'] < m['T'] ? "T" : "R";
    answer += m['C'] < m['F'] ? "F" : "C";
    answer += m['J'] < m['M'] ? "M" : "J";
    answer += m['A'] < m['N'] ? "N" : "A";
    
    return answer;
}