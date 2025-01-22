#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int count = 0;
    int size = citations.size();
    
    sort(citations.rbegin(), citations.rend());
    
    for(int i = 0; i < citations.size(); i++)
    {
        count++;
        if(count >= size - count)
        {
            if(citations[i] >= count)
            {
                for(int j = i + 1; j <= citations.size(); j++)
                {
                    if(j != citations.size() && citations[j] > count)
                        break;
                    return count;
                }
            }
                
        }
        
    }
    
    return answer;
}