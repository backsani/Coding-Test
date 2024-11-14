#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;
    
    int i = 0;
    for(int num : num_list){
        if(++i >= n)
            answer.push_back(num);
    }
    
    
    return answer;
}