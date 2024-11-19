#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    for(int n : num_list){
        int temp = n;
        while(temp != 1){
            if(temp % 2 != 0){
                temp--;
            }
            temp /= 2;
            answer++;
        }
        
    }
    
    return answer;
}