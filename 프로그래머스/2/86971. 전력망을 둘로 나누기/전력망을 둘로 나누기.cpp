#include <string>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    int min = INT_MAX;
    vector<vector<int>> temp = wires;
    
    for(int i = 0; i < wires.size(); i++)
    {
        set<int> a;
        set<int> b;
        int aValue = wires[i][0];
        int bValue = wires[i][1];
        
        a.insert(wires[i][0]);
        b.insert(wires[i][1]);
        
        while(a.size() + b.size() != n)
        {
            for(int j = 0; j < wires.size(); j++)
            {
                if(i != j)
                {

                    auto a0 = a.find(wires[j][0]);
                    auto a1 = a.find(wires[j][1]);
                    if(a0 != a.end() || a1 != a.end())
                    {
                        a.insert(wires[j][0]);
                        a.insert(wires[j][1]);
                    }

                    auto b0 = b.find(wires[j][0]);
                    auto b1 = b.find(wires[j][1]);
                    if(b0 != b.end() || b1 != b.end())
                    {
                        b.insert(wires[j][0]);
                        b.insert(wires[j][1]);
                    }
                }
            }
        }
        
        int result = a.size() - b.size();
        result = result > 0 ? result : result * -1;
        
        min = result < min ? result : min;
    }
    
    return min;
}