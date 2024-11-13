#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
    string answer = my_string;
    
    for(int i{}; i < my_string.size(); i++){
        if(my_string[i] == alp[0]){
            answer[i] = toupper(my_string[i]);
        }
    }
    
    return answer;
}