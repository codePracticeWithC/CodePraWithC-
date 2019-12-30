#include <stdio.h>


int number = 4; 
int INF = 10000000;


//자료 배열 초기화 

int a[4][4] = { 

    {0,5,INF,8},
    {7,0,9,INF},
    {2,INF,0,4},
    {INF,INF,3,0}

};


void FloydWarshall(){

    //결과 그래프 초기화 
    int d[number][number];

    for(int i = 0; i < number; i++){
        for(int j= 0; j < number; j++){
            d[i][j] = a[i][j];
        }
    }

    //거쳐가는 노드 k 
    for(int k = 0; k < number; k++){
        //시작노드 i 
        for(int i = 0 ; i < number; i++){
        //도착노드 j 
            for(int j = 0; j <number; j++){
                 if(d[i][k] + d[k][j] < d[i][j])
                 d[i][j] = d[i][k] + d[k][j];

            }
        }
    }


    for(int i = 0; i < number; i++){
        
        for(int j= 0; j < number; j++){
            printf("%d ", d[i][j] );
        }

        printf("\n");
    }



}


int main(void){

    FloydWarshall();

}
