
//이진트리 구현과 순회 알고리즘 
//기본적으로 포인터를 사용해 이진트리를 구현함 
//포인터를 사용하면 완전이진트리가 아닌 유동적인 이진트리 구현이 가능함 
//데이터를 탐색하는 방법에는 크게 3가지가 있음 

//1. 전위 순회 
//먼저 자기 자신을 처리함 
//그 다음 왼쪽 자식을 처리함 
//그 다음 오른쪽 자식을 처리함 

//2. 중위 순회 
//왼쪽자신을 처리함  
//자기 자신을 처리함 
//그 다음 오른쪽 자식을 처리함 

//3. 후위 순회 
//왼쪽자신을 처리함  
//오른쪽 자신을 처리함 
//자기 자신을 처리함 

#include <iostream>

using namespace std;

int number = 15;

// 하나의 노드정보를 선언함 
//node라는 이름의 구조체를 사용할거임 treePointer라는 이름으로 선언함 
typedef struct node *treePointer;

typedef struct node {
    int data;
    treePointer leftChild;
    treePointer rightChild;

}node;

// 전위 순회 
void preorder(treePointer tp){
    if(tp){ //포인터값이 null이 아니라면 
        cout << tp ->data << " "; //이 포인트의 데이터를 출력하고 
        preorder(tp->leftChild);
        preorder(tp->rightChild);
    }

}


//중위 순회 
void inorder(treePointer tp){
    if(tp){ //포인터값이 null이 아니라면 
        inorder(tp->leftChild);
        cout << tp ->data << " "; //이 포인트의 데이터를 출력하고 
        inorder(tp->rightChild);
    }

}

//후위 순회 
void postorder(treePointer tp){
    if(tp){ //포인터값이 null이 아니라면 
        postorder(tp->leftChild);
        postorder(tp->rightChild);
        cout << tp ->data << " "; //이 포인트의 데이터를 출력하고
    }

}

int main(void){

    node nodes[number+1];

    //그래프를 만들고 각자 자식 노드는 우선  비워둠 
    for(int i = 1; i <= number; i++){
        nodes[i].data= i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }

    //짝수는 왼쪽으로 홀수는 오른쪽으로 연결해줌 
    for(int i = 1; i <= number; i++){
        if(i % 2 == 0){
            nodes[i/2].leftChild = &nodes[i];
        }else{
            nodes[i/2].rightChild = &nodes[i];
        }
    }

    preorder(&nodes[1]);

    return 0;

}