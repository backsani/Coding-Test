#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b) {
    int answer = 0;
    int answer1 = 0;
    int answer2 = 0;
    int aCopy = a;
    int bCopy = b;
    int digitCount = 1;
    
    while(1){
        if(bCopy != 0){
            answer1 += (bCopy % 10) * digitCount;
            bCopy /= 10;
            digitCount *= 10;
            continue;
        }
        else if(aCopy != 0){
            answer1 += (aCopy % 10) * digitCount;
            aCopy /= 10;
            digitCount *= 10;
            continue;
        }
        break;
        
    }
    
    digitCount = 1;
    aCopy = a;
    bCopy = b;
    
    while(1){
        if(aCopy != 0){
            answer2 += (aCopy % 10) * digitCount;
            aCopy /= 10;
            digitCount *= 10;
            continue;
        }
        else if(bCopy != 0){
            answer2 += (bCopy % 10) * digitCount;
            bCopy /= 10;
            digitCount *= 10;
            continue;
        }
        break;
        
    }
    
    answer = (answer1 > answer2) ? answer1 : answer2;
    return answer;
}