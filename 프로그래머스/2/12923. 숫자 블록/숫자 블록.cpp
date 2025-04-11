#include <string>
#include <vector>
using namespace std;

int maxDivisor(long long n)
{
    if (n == 1) return 0;

    int result = 1;

    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            long long div1 = i;
            long long div2 = n / i;

            if (div2 <= 10000000)
                return (int)div2;

            if (div1 <= 10000000)
                result = max(result, (int)div1);
        }
    }

    return result;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    for (long long i = begin; i <= end; i++)
    {
        answer.push_back(maxDivisor(i));
    }

    return answer;
}
