#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ROT47 CRIPTAAAA */
int main()
{
    char inword[100],outword[100];
    int sizeofword,i;
    printf("\nIngrese la palabra a cifrar:\n");
    fflush(stdin);
    gets(inword);
    sizeofword = strlen(inword);
    for (i=0;i<sizeofword;i++){
        if (inword[i]<=122 && inword[i]>=65){
            outword[i] = inword[i] + 47;
            if (inword[i]>79){
                outword[i] = inword[i] - 47;
            }
        }
    }
    outword[sizeofword] = '\0';
    printf("\nPalabra cifrada: %s", outword);
    return 0;
}
