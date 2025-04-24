#include <string>
#include <vector>
#include <cctype>
#include <sstream>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    for(char& ch : my_string)
    {
        if(isalpha(ch))
            ch = ' ';
    }
    
    stringstream ss(my_string);
    string i;
    
    while(ss >> i)
    {
        answer += stoi(i);
    }
    
    return answer;
}