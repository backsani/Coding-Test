#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int coverage = 2 * w + 1;
    int left = 1; 

    for (int i = 0; i < stations.size(); i++)
    {
        int start = stations[i] - w;
        int end = stations[i] + w;

        if (left < start)
        {
            int gap = start - left;
            answer += ceil(static_cast<double>(gap) / coverage);
        }

        left = end + 1;
    }

    if (left <= n)
    {
        int gap = n - left + 1;
        answer += ceil(static_cast<double>(gap) / coverage);
    }

    return answer;
}