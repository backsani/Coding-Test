#include <string>
#include <vector>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int currentTime = (stoi(pos.substr(0, 2)) * 60) + stoi(pos.substr(3, 2));
    int videoLen = (stoi(video_len.substr(0, 2)) * 60) + stoi(video_len.substr(3, 2));
    int opStart = (stoi(op_start.substr(0, 2)) * 60) + stoi(op_start.substr(3, 2));
    int opEnd = (stoi(op_end.substr(0, 2)) * 60) + stoi(op_end.substr(3, 2));
    
    for(string command : commands){
        if(currentTime >= opStart && currentTime < opEnd){
            currentTime = opEnd;
        }
        if(command == "next"){
            currentTime = currentTime + 10 > videoLen ? videoLen : currentTime + 10;
        }
        else if(command == "prev"){
            currentTime = currentTime - 10 < 0 ? 0 : currentTime - 10;
        }
        if(currentTime >= opStart && currentTime < opEnd){
            currentTime = opEnd;
        }
    }
    
    int currentH = currentTime / 60;
    int currentM = currentTime % 60;
    
    answer += currentH < 10 ? "0" + to_string(currentH) : to_string(currentH);
    answer += ":";
    answer += currentM < 10 ? "0" + to_string(currentM) : to_string(currentM);
    
    return answer;
}