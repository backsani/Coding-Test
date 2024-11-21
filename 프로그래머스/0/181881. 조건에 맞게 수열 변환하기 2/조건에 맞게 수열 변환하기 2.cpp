#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    vector<int> prevArr;
    vector<int> currentArr = arr;
    
    while(prevArr != currentArr){
        prevArr = currentArr;
        for(int i{}; i < currentArr.size(); i++){
            if(currentArr[i] >= 50 && currentArr[i] % 2 == 0){
                currentArr[i] /= 2;
            }
            else if(currentArr[i] < 50 && currentArr[i] % 2 == 1){
                (currentArr[i] *= 2)++;
            }
        }
        answer++;
    }
    
    
    return --answer;
}