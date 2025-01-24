#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    double sum = 0;
    double mul = 0;

    string temp = "";
    
    vector<string> v1;
    vector<string> v2;
    
    for(char ch : str1)
    {
        if(!isalpha(ch))
        {
            temp = "";
            continue;
        }
        
        ch = toupper(ch);
        
        if(temp != "")
        {
            temp += ch;
            v1.push_back(temp);
            temp = ch;
        }
        else
        {
            temp += ch;
        }
    }
    
    temp = "";
    
    for(char ch : str2)
    {
        if(!isalpha(ch))
        {
            temp = "";
            continue;
        }
        
        ch = toupper(ch);
        
        if(temp != "")
        {
            temp += ch;
            v2.push_back(temp);
            temp = ch;
        }
        else
        {
            temp += ch;
        }
    }
    
    if(v1.empty() && v2.empty())
        return 65536;
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    int i = 0, j = 0;
        
    while(i < v1.size() && j < v2.size())
    {
        if(v1[i] == v2[j])
        {
            mul++;
            sum++;
            i++;
            j++;
        }
        else if(v1[i] > v2[j])
        {
            j++;
            sum++;
        }
        else if(v1[i] < v2[j])
        {
            i++;
            sum++;
        }
    }
    
    sum += (v1.size() - i) + (v2.size() - j);
    
    return (mul / sum) * 65536;
}