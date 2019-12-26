#include <stdio.h>

//점화식은 D[n] = D[n-1] + 2 * D[n-2]
//백준 11727
int memory[1001];

int dp(int x){

    if(x == 1) return 1;
    if(x == 2) return 3;
    
    if(memory[x] != 0) return memory[x];

    return memory[x] = (dp(x-1) + 2*dp(x-2)) % 10007;
   
    
}



int main(void){

    int n; 

    scanf("%d", &n);
    printf("%d",dp(n));

    return 0;

}