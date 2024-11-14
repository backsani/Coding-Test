#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = -1;
    int i = 0;
    
    for(int num : num_list){
        if(num < 0) {
            answer = i;
            break;
        }
        i++;
    }
    
    return answer;
}