#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    int i = 0;
    
    for(char c : myString){
        if(c != 'x'){
            i++;
        }
        else{
            answer.push_back(i);
            i = 0;
        }
        
    }
    answer.push_back(i);
    return answer;
}