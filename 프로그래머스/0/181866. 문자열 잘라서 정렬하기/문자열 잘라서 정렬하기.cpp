#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    string temp = "";
    
    for(char c : myString){
        if(c == 'x' && temp != ""){
            answer.push_back(temp);
            temp = "";
            continue;
        }
        if(c != 'x')
            temp += c;
        
    }
    
    if(!temp.empty()) answer.push_back(temp);
    
    sort(answer.begin(), answer.end());
    return answer;
}