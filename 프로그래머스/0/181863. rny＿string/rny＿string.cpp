#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string rny_string) {
    string answer = "";
    
    for(char str : rny_string){
        if(str == 'm'){
            answer += "rn";
            continue;
        }
        answer += str;
    }
    
    return answer;
}