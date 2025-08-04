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
        
        if(scoreCount[sum] <= 1)
            scoreSum.push_back(sum);
    }
    
    vector<int> ranks(201, 0);
    
    for(int i : scoreSum)
    {
        int rank = 1;
        
        for(int j : scoreSum)
        {
            if(i < j)
            {
                rank += scoreCount[j];
            }
        }
        
        ranks[i] = rank;
    }
    
    for(vector<int> v : score)
    {
        answer.push_back(ranks[v[0] + v[1]]);
    }
    
    return answer;
}