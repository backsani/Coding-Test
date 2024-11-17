#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    string answer = "";
    
    int i = 0;
    
    for(char str : n_str){
        if(str == '0'){
            i++;
            continue;
        }
        break;
    }
    
    for(i; i < n_str.size(); i++){
        answer += n_str[i];
    }
    
    return answer;
}