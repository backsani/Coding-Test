#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int size = elements.size();
    
    set<int> s;
    
    for(int i = 1; i < size + 1; i++)
    {
        for(int j = 0; j < size + 1; j++)
        {
            int repeat = i;
            int result = 0;
            while(repeat != 0)
            {
                repeat--;
                result += elements[(j + repeat) % size];
            }
            s.insert(result);
        }
    }
    
    return s.size();
}