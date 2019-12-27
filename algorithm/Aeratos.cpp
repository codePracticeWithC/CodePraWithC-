#include <stdio.h>
#include <math.h>


//정수 하나를 소수인지 아닌지 판별 하기 
bool isPrimeNumber(int x){
    int end =(int) sqrt(x); //x의 제곱근까지만 약수인지 확인해본다 
    
    for(int i = 2; i <= end; i++){
        if(x % i == 0){
            return false; 
        }
    }

    return true;

}


//에라토스테네스의 체 
//여러 정수들을 소수인지 아닌지 판별할때 쓰는 알고리즘 
//1. 이차원 배열을 생성하여 값을 초기화함 
//2. 2부터 시작해서 특정 숫자의 배수에 해당하는 숫자들을 모두 지움 (자기 자신은 지우지 않음)
//3. 이미 지워진 숫자는 건너 뜀 
//4. 지워지지 않고 남아있는 숫자들을 출력함

int number = 100000;

int data[100001];

void PrimNumberSieve(){
    
    //배열 초기화 
    for(int i = 2; i <= number; i++){
        data[i] = i;
    }

    for(int i = 2; i <= number; i++){
        //지워진 숫자라면 무시하고 
        if(data[i] == 0) continue;

        //i + i 인 이유는 자신을 제외한 다음 배수부터 비교하기 위함 
        // j += i 를 해주면 2 4 6 8 이런식으로 배수가 됨 
        for(int j = i + i; j <= number; j +=i){
            data[j] = 0;
        }

    }


}


int main(void){

    PrimNumberSieve();

    for(int i = 1; i <= number; i++){
        if(data[i] != 0)
        printf("%d    ", data[i]);
    }

    return 0;
}