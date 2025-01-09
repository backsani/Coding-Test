#include <string>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;



string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int,int> leftPos = make_pair(0,3);
    pair<int,int> rightPos = make_pair(2,3);
    
    for(int& i : numbers){
        if(i == 0)
            i = 11;
    }
    
    for(int pick : numbers)
    {
        if(pick % 3 == 1)
        {
            answer += "L";
            leftPos.first = 0;
            leftPos.second = (pick - 1) / 3;
        }
        else if(pick % 3 == 0)
        {
            answer += "R";
            rightPos.first = 2;
            rightPos.second = (pick - 1) / 3;
        }
        else if(pick % 3 == 2)
        {
            int leftDistance = abs(leftPos.first - 1) + abs(leftPos.second - (pick - 1) / 3);
            int rightDistance = abs(rightPos.first - 1) + abs(rightPos.second - (pick - 1) / 3);
            if(leftDistance == rightDistance)
            {
                if(hand == "right")
                {
                    answer += "R";
                    rightPos.first = 1;
                    rightPos.second = (pick - 1) / 3;
                }
                else
                {
                    answer += "L";
                    leftPos.first = 1;
                    leftPos.second = (pick - 1) / 3;
                }
            }
            else if(leftDistance > rightDistance)
            {
                answer += "R";
                rightPos.first = 1;
                rightPos.second = (pick - 1) / 3;
            }
            else
            {
                answer += "L";
                leftPos.first = 1;
                leftPos.second = (pick - 1) / 3;
            }
        }
    }
    
    return answer;
}