#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string word;
    
    for(char str : my_string){
        if(str == ' '){
            answer.push_back(word);
            word = "";
        }
        else{
            word += str;
        }
    }
    
    if(!word.empty()){
        answer.push_back(word);
    }
    
    return answer;
}