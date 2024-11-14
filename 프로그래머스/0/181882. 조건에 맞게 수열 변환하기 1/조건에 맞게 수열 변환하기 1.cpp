#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for(int i : arr){
        if(i % 2 == 0){
            if(i >= 50){
                i /= 2;
            }
        }
        else{
            if(i < 50){
                i *= 2;
            }
        }
        answer.push_back(i);
    }
    
    return answer;
}