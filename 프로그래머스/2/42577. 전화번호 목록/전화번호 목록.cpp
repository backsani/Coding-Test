#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    
    string prev = phone_book[0];
    for(int i = 1; i < phone_book.size(); i++)
    {
        if(phone_book[i].substr(0, prev.size()) == prev)
            return false;
        prev = phone_book[i];
    }
    
    return answer;
}