#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) {
    dot[0] = dot[0] > 0 ? 1 : 0;
    dot[1] = dot[1] > 0 ? 1 : 0;
    if(dot[0])
    {
        if(dot[1])
        {
            return 1;
        }
        return 4;
    }
    if(dot[1])
    {
        return 2;
    }
    return 3;
}