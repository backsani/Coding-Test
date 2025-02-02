#include <string>
#include <vector>

using namespace std;

string func(int n, int target)
{
    string str = "";
    
    while(target > 0)
    {
        int temp = target % n;
        target /= n;
        
        if(temp < 10)
            str = char(temp + '0') + str;
        else
            str = char(temp + 'A' - 10) + str;
    }
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string str = "0";
    int num = 1;
    
    //준비할 문자열 갯수 * 인원수 = 뽑아야되는 문자열 길이
    while(str.length() < t * m)
    {
        str += func(n, num);
        num++;
    }
    
    for(int i = 0; i < t; i++)
    {
        answer += str[i * m + p - 1];
    }
    
    return answer;
}