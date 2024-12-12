#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < arr1.size(); i++)
    {
        stack<int> tempV;
        for(int j = 0; j < arr1.size(); j++)
        {
            tempV.push((arr1[i] | arr2[i]) & 1 ? 1 : 0);
            arr1[i] = arr1[i] >> 1;
            arr2[i] = arr2[i] >> 1;
        }
        
        answer.push_back("");
        while(!tempV.empty())
        {
            answer[i] += tempV.top() ? "#" : " ";
            tempV.pop();
        }

    }
    
    return answer;
}