#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    bool pushNumber = false;
    vector<int> pushList;
    
    for(int n : arr){
        if(n == 2 && pushNumber == false){
            answer.push_back(n);
            pushNumber = true;
            pushList.clear();
        }
        else if(n != 2){
            pushList.push_back(n);
        }
        else if(n == 2 && pushNumber == true){
            for(int i : pushList){
                answer.push_back(i);
            }
            answer.push_back(n);
            pushList.clear();
        }
    }
    
    if(answer.empty() == true){
        answer.push_back(-1);
    }
    
    return answer;
}