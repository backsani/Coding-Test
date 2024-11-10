#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    
    for(string n : intStrs){
        int result = stoi((n.substr(s, l)));
        if(k < result){
            answer.push_back(result);
        }
    }
    
    return answer;
}