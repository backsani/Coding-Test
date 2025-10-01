#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sideLong(vector<int>& sides)
{
    int small = sides[1] - sides[0] + 1;
    return sides[1] - small + 1;
}

int anotherLong(vector<int>& sides)
{
    int big = sides[1] + 1;
    return sides[0] + sides[1] - big;
}

int solution(vector<int> sides) {
    int answer = 0;
    
    sort(sides.begin(), sides.end());
    
    return sideLong(sides) + anotherLong(sides);
}