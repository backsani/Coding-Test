#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    unordered_map<string, int> nameIndex;
    for(int i = 0; i < name.size(); i++){
        nameIndex[name[i]] = i;
    }
    
    for(vector<string> v : photo){
        int score = 0;
        for(string str : v){
            if(nameIndex.find(str) != nameIndex.end()){
                score += yearning[nameIndex[str]];
            }
        }
        answer.push_back(score);
    }
    
    return answer;
}