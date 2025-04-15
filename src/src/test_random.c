#include "../header/utils.h"
#include <stdio.h>
#include <stdlib.h>
#define EXIT_SUCCESS 0
int main(int argc, char *argv[])
{
    int random_num = gen_random_size(1, 5);
    printf("\n random numbr generated is %d \n",random_num);
    return EXIT_SUCCESS;
}
