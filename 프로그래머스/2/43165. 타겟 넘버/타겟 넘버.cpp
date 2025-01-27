#include <string>
#include <vector>

using namespace std;

int dfs(int index, int sum, vector<int> num, int target)
{
    if(index == num.size())
    {
        return target == sum ? 1 : 0;
    }
    
    return dfs(index + 1, sum + num[index], num, target) + dfs(index + 1, sum + num[index] * -1, num, target);
}


int solution(vector<int> numbers, int target) {
    return dfs(0, 0, numbers, target);
}