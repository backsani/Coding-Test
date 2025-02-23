#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    sort(data.begin(), data.end(), [col](vector<int> v1, vector<int> v2){
        if(v1[col-1] == v2[col-1])
            return v1[0] > v2[0];
        return v1[col-1] < v2[col-1];
    });
    
    vector<int> result;
    
    for(int i = row_begin - 1; i < row_end; i++)
    {
        int mod = i + 1;
        int sum = 0;
        
        for(int n : data[i])
        {
            sum += n % mod;
        }
        
        result.push_back(sum);
    }
    
    for(int i : result)
    {
        answer = answer ^ i;
    }
    
    return answer;
}