#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = sqrt(n);
    return sqrt(n) == answer ? 1 : 2;
}