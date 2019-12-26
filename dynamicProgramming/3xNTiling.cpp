#include <stdio.h>

//꼭 힌트를 보고 N-띠용을 생각해보자 힌트를 꼭 보자 
//점화식은 D[N] = 3 * D[N-2] + (2*D[N-4] + 2*D[N-6] + 2 * D[N-8] + .... + 2*D[0])
//N-2 일때 3가지 방법이 나옴 그리고 짝수일때마다 2가지가 더 나옴 

int memory[1001];

int dp(int x){
    if(x == 0) return 1; //아무것도 놓지 않는다 
    if(x == 1) return 0;
    if(x == 2) return 3;

    if(memory[x] != 0) return memory[x];

    int result = 3 * dp(x-2);

    for(int i = 3; i <= x; i++){
        if(i%2 == 0){
            result += 2 * dp(x-i);
        }
    }

    return memory[x] = result;

}

int main(void){

    int num; 

    scanf("%d", &num);
    printf("%d", dp(num));

    return 0;
}