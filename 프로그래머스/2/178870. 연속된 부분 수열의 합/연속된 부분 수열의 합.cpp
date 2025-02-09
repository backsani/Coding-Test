#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<pair<int, int>> result;
    
    int i = 0;
    int j = 0;
    int sum = sequence[i];
    while(true)
    {
        if(sum < k)
        {
            j++;
            if(j >= sequence.size())
                break;
            sum += sequence[j];
        }
        else if(sum > k)
        {
            sum -= sequence[i];
            i++;
            if(i > j)
                break;
        }
        else if (sum == k)
        {
            result.push_back(make_pair(i, j));
            j++;
            if(j >= sequence.size())
                break;
            sum += sequence[j];
        }
    }
    
    int min = INT_MAX;
    pair<int, int> minP;
    
    for(pair<int, int> p : result)
    {
        if(p.second - p.first < min)
        {
            minP = p;
            min = p.second - p.first;
        }
    }
    
    return {minP.first, minP.second};
}