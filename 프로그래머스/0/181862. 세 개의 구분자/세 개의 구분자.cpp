#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    string temp = "";
    
    for(char c : myStr){
        if((c == 'a' || c == 'b' || c == 'c') && temp != ""){
            answer.push_back(temp);
            temp = "";
        }
        if(!(c == 'a' || c == 'b' || c == 'c')) temp += c;
    }
    if(temp != "") answer.push_back(temp);
    if(answer.empty()) answer.push_back("EMPTY");
    
    return answer;
}