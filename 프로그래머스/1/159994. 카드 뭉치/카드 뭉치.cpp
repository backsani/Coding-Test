#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int i = 0;
    int pos1 = 0;
    int pos2 = 0;
    vector<string> v;
    
    while(!(pos1 == cards1.size() && pos2 == cards2.size()))
    {
        if(cards1[pos1] == goal[i])
        {
            i++;
            v.push_back(cards1[pos1]);
            pos1++;
            
            continue;
        }
        else if(cards2[pos2] == goal[i])
        {
            i++;
            v.push_back(cards2[pos2]);
            pos2++;
            
            continue;
        }
        else
        {
            if(goal == v)
                return "Yes";
            return "No";
        }
           
    }
    
    
    return "Yes";
}