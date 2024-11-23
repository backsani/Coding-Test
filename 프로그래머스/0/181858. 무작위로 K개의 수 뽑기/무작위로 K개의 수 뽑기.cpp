#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer(k, -1);
    
    for(int n : arr){
        int same = false;
        for(int i : answer){
            if(i == n){
                same = true;
            }
        }
        if(same == false){
            for(int& i : answer){
                if(i == -1){
                    i = n;
                    break;
                }
            }
        }
        
    }
    
    return answer;
}