#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    //입실 시간, 퇴실 시간을 담아두는 배열
    vector<pair<int, int>> v;
    
    for(vector<string> strV : book_time)
    {
        int inTime = 0;
        int outTime = 0;
        
        for(int i = 0; i < 2; i++)
        {
            stringstream ss(strV[i]);
            string num;
            int time = 0;

            while(getline(ss, num, ':'))
            {
                int temp = stoi(num);
                time = time * 60 + temp;
            }
            if(i == 0)
                inTime = time;
            else
                outTime = time;
        }
        
        v.push_back(make_pair(inTime, outTime));
    }
    
    sort(v.begin(), v.end(), [](pair<int, int> p1, pair<int, int>p2){
        return p1.first < p2.first;
    });
    
    //퇴실 시간만 저장하는 룸
    vector<int> room;
    
    for(pair<int, int> p : v)
    {
        bool newRoom = true;
        
        for(int& i : room)
        {
            if(p.first >= i)
            {
                i = p.second + 10;
                newRoom = false;
                break;
            }
        }
        
        if(newRoom)
            room.push_back(p.second + 10);
    }
    
    return room.size();
}