
#include <stdio.h>

int memory[100];

int dp(int x){
    if(x == 1) return 1;
    if(x == 2) return 1;
    if(memory[x] != 0) return memory[x];


    return memory[x] = dp(x-1) + dp(x-2); 
}

int main(void){

    printf("%d ", dp(6));

    return 0;
}