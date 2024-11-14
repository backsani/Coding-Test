#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> names) {
    vector<string> answer;
    int i = 4;
    
    for(string str : names){
        if(++i == 5){
            i = 0;
            answer.push_back(str);
        }
    }
    
    return answer;
}