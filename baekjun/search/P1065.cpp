#include <stdio.h>

//어떤 양의 정수 X의 자리수가 등차수열을 이룬다면, 
//그 수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다.
// N이 주어졌을 때, 1보다 크거나 같고, 
//N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 

void searchHansu(int n){

    int sum = 0;

  
    for(int i = 1; i <= n; i++){

        

        if(i <= 99) sum++;

        if(i >= 100){

            //1의자리수 
            int one = i % 10;
            //10의 자리수
            int ten = ( i / 10 ) % 10 ;
            //100의 자리수 
            int hundred = ( i / 10 ) / 10 ;

            if(hundred-ten == ten - one) sum++;
            

        }
    }

     printf("%d", sum);

  

}


int main(void){
    
    int num = 0;

    scanf("%d", &num);
    
    searchHansu(num);

}