#include <stdio.h>
#include <stdlib.h>
#include "../header/array.h"
/*#include "../header/utils.h"*/
#define EXIT_SUCCESS 0
int main(int argc, char *argv[])
{
    printf("welcome to world of problem solving");
    int* data =create_random_array(5);
    print_array(data,5);
    return EXIT_SUCCESS;
}
