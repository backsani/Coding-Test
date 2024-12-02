#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = phone_number;
    
    int answer_length = phone_number.size() - 4;
    
    for(char& c : answer)
    {
        if(answer_length > 0)
            c = '*';
        answer_length--;
    }
    
    return answer;
}