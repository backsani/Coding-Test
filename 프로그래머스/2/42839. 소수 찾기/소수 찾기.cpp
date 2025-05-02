#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int dfs(string numbers, string number, vector<bool>& v, set<int>& used)
{
    int count = 0;
    
    if(number != "")
    {
        int num = stoi(number);
        if(v[num] && used.find(num) == used.end())
        {
            used.insert(num); // 중복 방지
            count += 1;
        }
    }
    
    for(int i = 0; i < numbers.size(); i++)
    {
        string temp = number + numbers[i];
        
        string next = "";
        if(i != 0)
            next += numbers.substr(0, i);
        if(i != numbers.size() - 1)
            next += numbers.substr(i + 1, numbers.size() - i - 1);
        
        count += dfs(next, temp, v, used);
    }
    
    return count;
}


int solution(string numbers) {
    int answer = 0;
    
    sort(numbers.rbegin(), numbers.rend());
    
    int number = stoi(numbers);
    vector<bool> v(number+1, true);
    v[0] = false;
    v[1] = false;
    
    for(int i = 2; i*i <= number; i++)
    {
        int j = i + i;
        while(j <= number)
        {
            v[j] = false;
            j += i;
        }
    }
    
    set<int> used;
    answer = dfs(numbers, "", v, used);
    
    return answer;
}
