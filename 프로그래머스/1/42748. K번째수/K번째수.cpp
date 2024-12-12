#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    auto subVector = [array](vector<int> v){
            vector<int> intV;
            for(int i = v[0] - 1; i < v[1]; i++) 
            {
                intV.push_back(array[i]);
            }
            sort(intV.begin(), intV.end());
            return intV[v[2] - 1];
        };
    
    for(vector<int> v : commands)
    {
        answer.push_back(subVector(v));
    }
    
    
    return answer;
}