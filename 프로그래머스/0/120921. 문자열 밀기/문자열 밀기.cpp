#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    bool same = false;
    
    string temp = A;
    int size = A.size();
    
    if(A == B)
        return 0;
    
    for(int i = 0; !same && i < size; i++)
    {
        temp = temp[size - 1] + temp.substr(0, size - 1);
        answer++;
        
        if(temp == B)
            same = true;
    }
    
    return same ? answer : -1;
}