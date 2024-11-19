#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    int i = 0;
    int j = 1;
    
    for(int n : arr){
        i++;
        if(i > j)
        {
            j *= 2;
        }
    }
    answer.resize(j);
    
    return answer;
}