#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    vector<int> a(topping.size(), 0);
    vector<int> b(topping.size(), 0);
    set<int> s;
    
    for(int i = 0; i < topping.size(); i++)
    {
        s.insert(topping[i]);
        a[i] = s.size();
    }
    
    s.clear();
    
    for(int i = topping.size() - 1; i > -1; i--)
    {
        if(i == 0)
        {
            
        }
        s.insert(topping[i]);
        b[i] = s.size();
    }
    
    for(int i = 0; i < topping.size() - 1; i++)
    {
        if(a[i] == b[i + 1])
        {
            answer++;
        }
    }
    
    return answer;
}