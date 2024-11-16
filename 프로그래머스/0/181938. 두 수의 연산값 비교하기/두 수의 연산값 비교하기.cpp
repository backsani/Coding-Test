#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int as = stoi(to_string(a) + to_string(b));
    return 2*a*b > as ? 2*a*b : as;
}