#include <string>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    stringstream ss(s);
    stack<int> numbers;
    
    string num;
    
    while(getline(ss, num, ' '))
    {
        if(num == "Z")
            numbers.pop();
        else
        {
            numbers.push(stoi(num));
        }
    }
    
    while(!numbers.empty())
    {
        answer += numbers.top();
        numbers.pop();
    }
    
    return answer;
}