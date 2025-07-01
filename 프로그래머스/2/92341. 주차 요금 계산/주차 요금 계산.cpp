#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    string time;
    string carNumber;
    string state;
    
    map<string, int> mTotal;
    map<string, pair<int, bool>> mIn;
    
    int basicTime = fees[0];
    int basicCost = fees[1];
    int UnitTime = fees[2];
    int unitCost = fees[3];

    for(string str : records)
    {
        stringstream ss(str);
        ss >> time >> carNumber >> state;
        
        int hour = stoi(time.substr(0, 2));
        int min = stoi(time.substr(3, 2));
        int temp = hour * 60 + min;
        
        if(state == "IN")
        {
            mIn[carNumber] = {temp, false};
        }
        else if(state == "OUT")
        {
            temp = temp - mIn[carNumber].first;
            mTotal[carNumber] = mTotal[carNumber] + temp;
            mIn[carNumber].second = true;
        }
    }
    
    for(pair<string, pair<int, bool>> p : mIn)
    {
        if(p.second.second == false)
        {
            mTotal[p.first] = mTotal[p.first] + (1439 - p.second.first);
        }
    }
    
    map<string, int> cost;
    for(pair<string, int> p : mTotal)
    {
        int t = p.second;
        if(t <= basicTime)
        {
            cost[p.first] = basicCost;
        }
        else
        {
            cost[p.first] = basicCost + static_cast<int>(ceil((p.second - basicTime) / (float)UnitTime) * unitCost);
        }
    }
    
    for(pair<string, int> p : cost)
    {
        answer.push_back(p.second);
    }
    
    return answer;
}