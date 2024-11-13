#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer(strArr.size());
    
    for(int i{}; i < strArr.size(); i++){
        if((i + 1) % 2 != 0){
            for(char c : strArr[i]){
                answer[i] += tolower(c);
            }
        }
        else{
            for(char c : strArr[i]){
                answer[i] += toupper(c);
            }
        }
    }
    
    return answer;
}