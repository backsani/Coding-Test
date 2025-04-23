#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    if(common[1] - common[0] == common[2] - common[1])
    {
        int temp = common[1] - common[0];
        return common[common.size() - 1] + temp;
    }
    else
    {
        int temp = common[1] / common[0];
        return common[common.size() - 1] * temp;
    }
    
    return -1;
}