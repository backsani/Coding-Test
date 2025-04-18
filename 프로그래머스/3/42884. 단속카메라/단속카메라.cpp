#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    vector<vector<int>> beginRoutes = routes;
    
    sort(beginRoutes.begin(), beginRoutes.end(), [](vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    });
    sort(routes.begin(), routes.end(), [](vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    });
    
    int routesIndex = 0;
    int beginIndex = 0;
    
    int lastPos = INT_MIN;
    
    while(routesIndex < routes.size() && routesIndex != routes.size())
    {
        if(lastPos >= routes[routesIndex][0])
        {
            routesIndex++;
            continue;
        }
        
        int temp = routes[routesIndex][1];
        
        while(beginIndex < routes.size() && beginRoutes[beginIndex][0] <= temp)
        {
            beginIndex++;
        }
        
        lastPos = temp;
        answer++;
        routesIndex++;
    }
    
    return answer;
}