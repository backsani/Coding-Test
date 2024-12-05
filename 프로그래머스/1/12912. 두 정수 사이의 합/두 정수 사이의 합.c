#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;
    
    int x = a > b ? a : b;
    int y = a < b ? a : b;
    
    for(int i = y; i < x +1; i++)
        answer += i;
    
    return answer;
}