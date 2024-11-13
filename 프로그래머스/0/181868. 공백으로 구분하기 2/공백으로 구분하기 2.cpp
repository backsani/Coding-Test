#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string word = "";
    
    for(int i{}; i < my_string.size() + 1; i++){
        if(my_string[i] == ' ' || my_string[i] == '\0'){
            if(word != "")
                answer.push_back(word);
            word = "";
            continue;
        }
        else{
            word += my_string[i];
        }
            
    }
    
    return answer;
}