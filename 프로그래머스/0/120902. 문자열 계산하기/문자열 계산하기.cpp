#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    stringstream ss(my_string);
    vector<int> num;
    vector<char> op;
    
    string str;
    
    while(ss >> str)
    {
        for(char ch : str)
        {
            if(isdigit(ch))
            {
                num.push_back(stoi(str));
                break;
            }
            if((ch == '+' || ch == '-') && str.size() == 1)
                op.push_back(ch);
        }
        
    }
    
    answer = num[0];
    for(int i = 1; i < num.size(); i++)
    {
        if(op[i-1] == '+')
            answer += num[i];
        else if(op[i-1] == '-')
            answer -= num[i];
    }
    
    return answer;
}