#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for(char str : myString){
        answer += toupper(str);
    }
    return answer;
}