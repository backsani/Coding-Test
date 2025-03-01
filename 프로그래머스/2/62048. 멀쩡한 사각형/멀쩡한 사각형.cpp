using namespace std;

int gcd(int a, int b)
{
    int result = a % b;
    if(result == 0)
        return b;
    
    return gcd(b, result);
}

long long solution(int w,int h) {
    long long answer = 1;

    
    return (long long)w * h - (w + h - gcd(w,h));
}