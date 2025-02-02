#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long> v;
    
    v.push_back(1);
    v.push_back(2);
    
    for(int i = 2; i < n; i++)
    {
        v.push_back((v[i - 1] + v[i - 2]) % 1234567);
    }
    
    return v[n - 1];
}