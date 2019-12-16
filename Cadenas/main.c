#include <stdio.h>
#include <stdlib.h>

int main()
{
    char frase[20];
    int vocal_a=0;
    int vocal_e=0;
    int vocal_i=0;
    int vocal_o=0;
    int vocal_u=0;

    printf("Digite una frase: ");
    gets(frase);

    for(int i=0;i<20;i++)
    {
        switch(frase[i])
        {
            case 'a': vocal_a++; break;
            case 'e': vocal_e++; break;
            case 'i': vocal_i++; break;
            case 'o': vocal_o++; break;
            case 'u': vocal_u++; break;
        }
    }

    printf("Vocal A:  %d \n", vocal_a);
    printf("Vocal E:  %d \n", vocal_e);
    printf("Vocal I:  %d \n", vocal_i);
    printf("Vocal O:  %d \n", vocal_o);
    printf("Vocal U:  %d \n", vocal_u);

    return 0;
}
