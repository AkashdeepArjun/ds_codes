#include <stdio.h>
#include <stdlib.h>
#define EXIT_SUCCESS 0

int give_three();
int main(int argc, char *argv[])
{
    printf(" response is %d\n",give_three());
    return EXIT_SUCCESS;
}

int give_three(){
    
    int count=1;
    int c=4;
    while(1>0){

  while(count<=10){
        if(count==3){
            return count;
        }
        count+=1;
    }

    

    }
  
}
