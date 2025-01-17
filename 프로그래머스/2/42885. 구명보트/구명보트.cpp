#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int frontP = 0;
    int backP = people.size() - 1;
    
    while(frontP <= backP)
    {
        if(frontP == backP)
        {
            answer++;
            backP--;
        }
        else if(people[frontP] + people[backP] <= limit)
        {
            answer++;
            frontP++;
            backP--;
        }
        else if(people[frontP] + people[backP] > limit)
        {
            answer++;
            backP--;
        }
    }
    
    return answer;
}