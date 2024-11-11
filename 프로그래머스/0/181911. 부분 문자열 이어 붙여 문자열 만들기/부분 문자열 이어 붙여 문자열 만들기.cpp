#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) {
    string answer = "";
    int i = 0;
    
    for(vector<int> n : parts){
        
        answer += my_strings[i].substr(n[0], n[1] - n[0] + 1);
        
        i++;
    }
    
    return answer;
}