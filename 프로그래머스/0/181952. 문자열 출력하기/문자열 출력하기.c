#include <stdio.h>
#define LEN_INPUT 1000001

int main(void) {
    char s1[LEN_INPUT];
    scanf("%s", s1);
    
    for(int i = 0; i < LEN_INPUT; i++)
    {
        if(s1[i] == '\0')
        {
            break;
        }
        printf("%c", s1[i]);
    }
    

    return 0;
}
