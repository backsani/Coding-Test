#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    char alpha[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    
    string temp = to_string(age);
    
    for(char ch : temp)
    {
        answer += alpha[ch - '0'];
    }
    
    return answer;
}