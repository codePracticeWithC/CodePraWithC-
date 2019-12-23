#include <stdio.h>
#include <string>
#include <iostream>

int getParent(int parent[], int i){

    if(parent[i] == i)
    return i; 

    return parent[i] = getParent(parent, parent[i]);
}

int unionParent(int parent[], int a, int b){

 a = getParent(parent, a);
 b = getParent(parent ,b);

    if(a < b){
        parent[b] = a;
    }else{
        parent[a] = b;
    }

    return 0;

}

std::string checkParent(int parent[], int a , int b){

    a = getParent(parent,a);
    b = getParent(parent,b);
    
    if(a == b){
        return "그래프가 같습니다";
    }else{
        return "그래프가 서로 다릅니다";
    }

}



int main(void){

    int parent[11];

    for(int i = 1; i <= 10; i++){
        parent[i] = i;
    }

    unionParent(parent,1,2);
    unionParent(parent,2,3);
    unionParent(parent,2,8);

    std::cout << checkParent(parent,1,8);

    return 0;
}