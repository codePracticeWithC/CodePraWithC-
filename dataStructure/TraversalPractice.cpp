#include <iostream>

using namespace std;

int number = 15;

typedef struct node *treePointer;

typedef struct node {
    int data;
    treePointer leftchild;
    treePointer rightchild;

}node;



void preorder(treePointer tcp){
    if(tcp){
    cout << tcp->data << " ";
    preorder(tcp->leftchild);
    preorder(tcp->rightchild);
    }
}

void inorder(treePointer tcp){
    if(tcp){
    inorder(tcp->leftchild);
    cout << tcp->data << " ";
    inorder(tcp->rightchild);
    }
}

void postorder(treePointer tcp){
    if(tcp){
        postorder(tcp->leftchild);
        postorder(tcp->rightchild);
        cout << tcp->data << " ";
    }

}



int main(void){

   node nodes[number+1];

   for(int i = 1; i <= number; i++){
       nodes[i].data = i;
       nodes[i].leftchild = NULL;
       nodes[i].rightchild = NULL;
    }

    for(int i = 1; i <= number; i++){
        if(i % 2 == 0){
            nodes[i/2].leftchild = &nodes[i];
        }else{
            nodes[i/2].rightchild = &nodes[i];
        }


    }



    preorder(&nodes[1]);


    return 0;
}