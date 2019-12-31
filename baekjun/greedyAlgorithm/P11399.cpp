#include <stdio.h>
#include <algorithm>


using namespace std;




int main(void){



    int n; 

    scanf("%d", &n);

    int person[1001];


    for(int i = 0; i < n; i++){

        int time = 0;

        scanf("%d" , &time);

        person[i] = time;

    }

    sort(person, person + n);


    int sum = 0 ;

    for(int i = 0; i < n; i++){

     for(int j = 0 ; j <= i; j++){
         sum += person[j];
     }

    }

    printf("%d" ,sum);
    

    return 0;
}