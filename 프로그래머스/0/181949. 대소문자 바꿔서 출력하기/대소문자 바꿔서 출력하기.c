#include <stdio.h>
#define LEN_INPUT 21

int main(void) {
    char s1[LEN_INPUT];
    scanf("%20s", s1);
    
    for(int i = 0; i < LEN_INPUT; i++){
        if(s1[i] == '\0')
            break;
        if(s1[i] >= 65 && s1[i] <= 90){
            s1[i] = s1[i] + 32;
        }
        else if(s1[i] >= 97 && s1[i] <= 122){
            s1[i] = s1[i] -32;
        }
    }
    
    printf("%s", s1);

    return 0;
}
