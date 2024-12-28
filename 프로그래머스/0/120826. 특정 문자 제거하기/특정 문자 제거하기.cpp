#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    for(char ch : my_string)
    {
        if(letter[0] != ch)
            answer += ch;
    }
    
    return answer;
}