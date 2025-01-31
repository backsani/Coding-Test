#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

bool isPrime(long long num) {
    if (num < 2) return false;
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    stack<int> s;
    
    while(n != 0)
    {
        s.push(n % k);
        n /= k;
    }
    
    string str = "";
    
    while(!s.empty())
    {
        str += to_string(s.top());
        s.pop();
    }
    
    stringstream ss(str);
    string num;
    
    while(getline(ss, num, '0'))
    {
        if (!num.empty())
        {
            if(isPrime(stoll(num)))
                answer++;
        }
    }

    return answer;
}