#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    
    for(int n{}; n < arr.size(); n++){
        for(int i : delete_list){
            if(arr[n] == i){
                arr.erase(arr.begin() + n);
                --n;
            }
        }
    }
    
    answer = arr;
    
    return answer;
}