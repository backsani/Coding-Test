#include <string>
#include <vector>
#include <cmath>

using namespace std;

void makeHailstone(int n, vector<pair<int, int>>& v)
{
    int i = 0;
    while(true)
    {
        v.push_back(make_pair(i, n));
        
        if(n == 1)
            break;
        
        if(n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = n * 3 + 1;
        }
        i++;
    }
}

void makeIntegral(vector<double>& answer, vector<pair<int, int>> v, vector<vector<int>> ranges)
{
    for(vector<int> scope : ranges)
    {
        int x, y;
        x = scope[0];
        y = scope[1];
        if(y <= 0)
        {
            y = v.size() - 1 + scope[1];
        }
        if(x > y)
        {
            answer.push_back(-1);
            continue;
        }
        
        double sum = 0;
        
        for(int i = x + 1; i < y + 1; i++)
        {
            double n = abs(v[x].second - v[i].second);
            
            sum += n / 2;
            sum += min(v[x].second, v[i].second);

            x++;
        }
        
        answer.push_back(sum);
    }
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<pair<int, int>> hailstone;
    
    makeHailstone(k, hailstone);
    makeIntegral(answer, hailstone, ranges);
    
    return answer;
}