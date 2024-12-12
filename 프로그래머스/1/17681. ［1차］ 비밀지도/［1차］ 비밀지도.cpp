#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < arr1.size(); i++)
    {
        answer.push_back("");
        for(int j = 0; j < arr1.size(); j++)
        {
            answer[i] = (((arr1[i] | arr2[i]) & 1 ? 1 : 0) ? "#" : " ") + answer[i];
            arr1[i] = arr1[i] >> 1;
            arr2[i] = arr2[i] >> 1;
        }
        

    }
    
    return answer;
}