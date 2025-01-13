#include <string>
#include <vector>
#include <sstream>
#include <utility>


using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<pair<char, int>> v;
    pair<int, int> currentPos;
    
    int i = 0;
    bool stop = false;
    for(string str : park)
    {
        int j = 0;
        if(stop)
            break;
        for(char ch : str)
        {
            if(stop)
                break;
            
            if(ch == 'S')
            {
                currentPos = make_pair(i,j);
                stop = true;
            }
            j++;
        }
        i++;
    }
    
    for(string str : routes)
    {
        stringstream ss(str);
        char direction;
        int count;
        ss >> direction >> count;
        
        v.push_back(make_pair(direction, count));
    }
    
    for(pair<char, int> p : v) {
        int prevPosX = currentPos.second;
        int prevPosY = currentPos.first;
        
        for(int t = 0; t < p.second; t++) {
            bool moved = false;
            switch(p.first) {
                case 'E':
                    if(currentPos.second + 1 < park[0].size() && park[currentPos.first][currentPos.second + 1] != 'X') {
                        currentPos.second += 1;
                        moved = true;
                    }
                    break;
                case 'W':
                    if(currentPos.second - 1 >= 0 && park[currentPos.first][currentPos.second - 1] != 'X') {
                        currentPos.second -= 1;
                        moved = true;
                    }
                    break;
                case 'S':
                    if(currentPos.first + 1 < park.size() && park[currentPos.first + 1][currentPos.second] != 'X') {
                        currentPos.first += 1;
                        moved = true;
                    }
                    break;
                case 'N':
                    if(currentPos.first - 1 >= 0 && park[currentPos.first - 1][currentPos.second] != 'X') {
                        currentPos.first -= 1;
                        moved = true;
                    }
                    break;
            }
            
            if (!moved) {
                currentPos.second = prevPosX;
                currentPos.first = prevPosY;
                break;
            }
        }
    }
    
    return {currentPos.first, currentPos.second};
}