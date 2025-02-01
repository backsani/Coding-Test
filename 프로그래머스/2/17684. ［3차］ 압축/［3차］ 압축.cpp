#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dictionary;
    
    int index = 1;
    for(; index <= 'Z' - 'A' + 1; index++)
    {
        dictionary[string(1, index + 'A' - 1)] = index;
    }
    
    for(int i = 0; i < msg.size(); i++)
    {
        string str = "";
        str += msg[i];
        int j = 0;
        
        string prevStr = "";
        
        while(dictionary.find(str) != dictionary.end())
        {
            prevStr = str;
            j++;
            str += msg[i + j];
        }
        dictionary[str] = index;
        index++;
        
        i += j - 1;
        
        answer.push_back(dictionary[prevStr]);
    }
    
    
    
    return answer;
}