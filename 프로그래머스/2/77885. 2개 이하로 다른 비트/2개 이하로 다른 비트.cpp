#include <string>
#include <vector>
#include <bitset>

using namespace std;
typedef long long ll;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(ll& n : numbers) {
        ll idx = (~n & -~n);
        ll ans = n + idx - (idx >> 1);
        answer.push_back(ans);
    }
    return answer;
}