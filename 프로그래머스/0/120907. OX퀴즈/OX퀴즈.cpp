#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for(string str : quiz)
    {
        stringstream ss(str);
        int a, b, c;
        char op;
        char temp;
        
        ss >> a >> op >> b >> temp >> c;
        
        int result;
        if(op == '-')
        {
            result = a- b;
        }
        else if(op == '+')
        {
            result = a + b;
        }
        
        answer.push_back(result == c ? "O" : "X");
    }
    
    return answer;
}