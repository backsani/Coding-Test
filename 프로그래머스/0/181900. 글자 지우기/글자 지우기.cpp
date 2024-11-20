#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string copyString = my_string;
    string answer = "";
    
    for(int n : indices){
        copyString[n] = ' ';
    }
    
    for(char c : copyString){
        if(c == ' '){
            continue;
        }
        answer += c;
    }
    
    return answer;
}