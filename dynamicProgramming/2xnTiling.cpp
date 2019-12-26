#include <stdio.h>

//2 x n 개의 직사각형에 2 x 1 , 1 x 2 타일로 채워넣을 수 있는 방법의 수 는 ? 
//점화식 D[i] = D[i-1] + D[i-2]
//백준 11726

int memory[1001];

int dp(int x){
    if(x == 1) return 1;
    if(x == 2) return 2;
    if(memory[x] != 0) return memory[x];
    return memory[x] = (dp(x-1) + dp(x-2)) % 10007;

}


int main(void){

    int num;

    scanf("%d", &num);

    printf("%d", dp(num));    

    return 0 ;
}