#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code) {
    string answer = "";
    int i = 0;
    for(char ch : cipher)
    {
        if(++i == code)
        {
            i = 0;
            answer += ch;
        }
    }
    return answer;
}