
#include <stdio.h>


int main(void){


    int bird; 

    scanf("%d" , &bird);

    
    int k = 1;
    int count = 0;

    while( bird != 0){

        if( k > bird){
            k = 1; 
        }

        bird = bird - k;
        k++;
        count++;

    }

    printf("%d", count);

}
