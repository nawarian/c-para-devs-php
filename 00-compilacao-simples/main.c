#include "arquivo2.c"
#include "arquivo1.c"

int main(void)
{
    int x = 0;
    x += arquivo1();
    x += arquivo2();

    return x;
}

