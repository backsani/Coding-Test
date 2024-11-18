#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    int answer = 0;
    string currentPrefix = "";
    for(char c : my_string){
        currentPrefix += c;
        if(currentPrefix == is_prefix){
            answer = 1;
            break;
        }
    }
    return answer;
}