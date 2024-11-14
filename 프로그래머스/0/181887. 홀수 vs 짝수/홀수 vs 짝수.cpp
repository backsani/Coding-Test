#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int a = 0,b = 0;
    
    for(int i = 0; i < num_list.size(); i++){
        ((i + 1) % 2 != 0 ? a : b) += num_list[i];
    }
    
    return a >= b ? a : b;
}