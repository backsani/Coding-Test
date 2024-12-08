#include <string>
#include <vector>

using namespace std;

int calculBaseThree(int number, int pos)
{
    int sum = number;
    if(pos != 0)
    {
        sum = calculBaseThree(number * 3, pos - 1);
    }
    return sum;
}

int solution(int n) {
    int answer = 0;
    string temp = "";
    
    vector<int> v;
    while(n != 0)
    {
        v.push_back(n%3);
        n/=3;
    }
    
    int i = 0;
    while(!v.empty())
    {
        answer += calculBaseThree(v.back(), i);
        v.pop_back();
        i++;
    }
    
    return answer;
}