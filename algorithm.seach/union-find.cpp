



//Union-Find 합집합 찾기 
//1,2,3 이 연결되어있을때 
//1 2 3 4 5 6 7 8  
//1 1 2 4 5 6 7 8  이런식으로 표현할 수있다 
//여기서 재귀 함수를 이용해서 
//1 1 1 4 5 6 7 8  (2,3 모두 1이 부모로 연결되어있다는 뜻)로 처리할 수 있다 
//그러면 1,2,3 은 1을 부모 노드로 갖고있기때문에 같은 그래프에 속해있다고 할 수 있다 

#include <stdio.h>

//부모 노드를 찾는 함수 
int getParent(int parent[], int x){
    if(parent[x] == x)
    return x; //재귀호출을 반복한 뒤 부모일경우 종료시킨다 (부모까지 재귀가 돌았다는 뜻)
    

    //부모노드까지 도착하지 않았다면 
    printf("parent[x] : %d ", parent[x]);

    //부모의 부모를 찾고 부모의 부모를 찾고...
    //1-2   2-3 연결을 예로들면 
    //parent 배열상에서는 1,2,3 연결이 안되어있으니까 
    //EX) int x = 3 이면 2 != 3 이니까 다시 int x= 2로 실행 2 != 1이니까 다시 int = 1 1 == 1 이니까 재귀종료 
   return parent[x] = getParent(parent,parent[x]);
}

//두 부모 노드를 합치는 함수 
int unionParent(int parent[], int a, int b){
    a = getParent(parent,a);
    b = getParent(parent,b);
    if(a < b) {
        parent[b] = a ;   //EX 2의 부모는 1, 3의 부모는 2인데 1로합쳐져야하기때문에 작은쪽으로 부모를 합쳐준다 
    }else{
        parent[a] = b;
    }

    return 0;
}

//같은 부모를 가지는지 확인
int findParent(int parent[],int a ,int b){
    a = getParent(parent, a);
    b = getParent(parent,b);

    if(a == b){
    return 1; //만약 부모가 같다면 (같은 그래프에 속해있다면)      
    }else{
     return 0;
    }
}

int main(void){

    int parent[11];

    for(int i = 1; i <= 10; i++){ //i는 1부터임 
        parent[i] = i;
    }
    
    unionParent(parent,1,2);
    unionParent(parent,2,4);
    unionParent(parent,3,5);


    printf("같은 그래프인가요? : %d ", findParent(parent,3,5));

    

    
   

}



