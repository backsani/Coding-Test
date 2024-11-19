#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d2, vector<int> d1) {
    return (d1[0] > d2[0]) || (d1[0] >= d2[0] && d1[1] > d2[1]) || (d1[0] >= d2[0] && d1[1] >= d2[1] && d1[2] > d2[2]);
}