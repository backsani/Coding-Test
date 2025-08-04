#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    
    vector<int> scoreCount(201, 0);
    vector<int> scoreSum;
    
    for(vector<int> v : score)
    {
        int sum = v[0] + v[1];
        scoreCount[sum]++;
        
        scoreSum.push_back(sum);
    }
    
    
    for(int i : scoreSum)
    {
        int rank = 1;
        
        for(int j = i + 1; j <= 200; j++)
        {
            rank += scoreCount[j];
        }
        
        answer.push_back(rank);
    }
    
    return answer;
}