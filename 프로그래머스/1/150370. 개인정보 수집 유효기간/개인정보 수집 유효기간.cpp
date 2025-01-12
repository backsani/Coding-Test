#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cctype>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, int> m;
    
    for(string str : terms)
    {
        stringstream ss(str);
        string type;
        int month;
        ss >> type >> month;
        m[type] = month;
    }
    
    vector<int> todayV;
    {
        stringstream ss(today);
        string temp;
        while(getline(ss, temp, '.'))
        {
            todayV.push_back(stoi(temp));
        }
    }
    
    
    
    for(int i = 0; i < privacies.size(); i++)
    {
        stringstream ss(privacies[i]);
        vector<int> v;
        string date;
        string type;
        
        ss >> date >> type;
        
        stringstream ssDate(date);
        string temp;
        
        while(getline(ssDate, temp, '.'))
        {
            v.push_back(stoi(temp));
        }
        v[1] += m[type];
        
        privacies[i] = privacies[i].substr(0, 10);
        
        while(v[1] > 12)
        {
            v[1] -= 12;
            v[0]++;
        }
        
        v[2] -= 1;
        
        if (v[0] < todayV[0] || (v[0] == todayV[0] && v[1] < todayV[1]) || (v[0] == todayV[0] && v[1] == todayV[1] && v[2] < todayV[2])) 
        {
            answer.push_back(i + 1);
        }
    }
    
    
    return answer;
}