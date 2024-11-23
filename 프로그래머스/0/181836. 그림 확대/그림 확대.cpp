#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer(picture.size() * k);
    int length = 0;
    
    for(string str : picture){
        for(int i{}; i < k; i++){
            for(char c : str){
                for(int j{}; j < k; j++){
                    answer[length] += c;
                }
            }
        length++;
        }
    }
    
    return answer;
}