#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int gameStart(vector<int>& cards)
{
    int startIndex = -1;
    int openCount = 0;
    for(int i = 0; i < cards.size(); i++)
    {
        if(cards[i] != 0)
        {
            startIndex = i;
            break;
        }
            
    }
    if(startIndex == -1)
        return 0;
    
    while(cards[startIndex] != 0)
    {
        int nextIndex = cards[startIndex] - 1;
        cards[startIndex] = 0;
        startIndex = nextIndex;
        openCount++;
    }
    
    return openCount;
}

int solution(vector<int> cards) {
    int answer = 0;
    
    vector<int> result;
    
    while(true)
    {
        int temp = gameStart(cards);
        result.push_back(temp);
        if(temp == 0)
            break;
    }
    
    sort(result.rbegin(), result.rend());
    
    return result[0] * result[1];
    //return cards[0];
}