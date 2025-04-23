#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {
    long long result = 1;

    // share = r, balls = n
    // result = n! / (n-r)! / r! 를 순서대로 계산
    for (int i = 1; i <= share; i++) {
        result *= balls--;  // 분자: n * (n-1) * ... * (n-r+1)
        result /= i;        // 분모: r!
    }

    return (int)result;
}
