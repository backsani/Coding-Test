#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    int distance = 100;
    
    sort(array.begin(), array.end());
    
    for(int i : array)
    {
        if(abs(n - i) < distance)
        {
            distance = abs(n - i);
            answer = i;
        }
    }
    
    return answer;
}