#include <iostream>

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
    std::cout << mod_exp(1,2,3) << std::endl;
    return 0;
}