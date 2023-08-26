//$ diffie-‐hellman
//Send the number X: 160 to your partner.
//Enter the Y number that your partner has sent you: 425
//The shared secret key is: 352

#include <stdio.h>
#include <stdlib.h>

int mod_exp(int b, int e, int p) {
    int i,x,power;
    x = 1;
    power = b % p;
    for (i=0;i<8*sizeof(int);i++) {
        if (e & 1) {
            x = (x*power) % p;
        }
        e >>= 1;
        power = (power*power) % p;
    }
    return x;
}

int main(int argc, char const *argv[])
{
    
    int x = rand(); //Número que enviaremos a nuestro compañero
    int y; //Número que nuestro compañero nos envió
    int p = 761; //Número primo
    int r = 6; //Raiz primitiva
    
    printf("Send the number X: %d to tour partner\n", x);
    printf("Enter the Y number that your partner has sent you: ");
    scanf("%d", &y);
    printf("The shared secret key is: %d", mod_exp(y,r,p));

    return 0;
}