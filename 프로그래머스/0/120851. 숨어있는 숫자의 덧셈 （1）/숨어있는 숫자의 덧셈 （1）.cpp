#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    for(char ch : my_string)
    {
        if(ch > '0' && ch <= '9')
            answer += ch - '0';
    }
    return answer;
}