#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for(char str : myString){
        answer += tolower(str);
    }
    
    replace(answer.begin(), answer.end(), 'a', 'A');
    
    return answer;
}