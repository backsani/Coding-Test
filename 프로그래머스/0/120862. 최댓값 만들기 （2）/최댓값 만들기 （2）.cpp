#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    int nSize = numbers.size();
    answer = numbers[nSize - 1] * numbers[nSize - 2] > numbers[0] * numbers[1] ? numbers[nSize - 1] * numbers[nSize - 2] : numbers[0] * numbers[1];
    return answer;
}