#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> str_list, string ex) {
    vector<string> copy_list;
    copy_list = str_list;
    string answer = "";
    
    int i = 0;
    
    while(copy_list.size() != i)
    {
        if(copy_list[i].find(ex) != -1){
            copy_list.erase(copy_list.begin() + i);
            continue;
        }
        i++;
    }
    
    for(string str : copy_list){
        answer += str;
    }
    
    return answer;
}