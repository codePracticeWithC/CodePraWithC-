
#include <stdio.h>
#include <vector>
#include <queue>


using namespace std;


typedef struct Tree{

    int val;
    int parent;
    vector<int> child;

}Tree;



queue<int> q;
Tree tree[52];

int cnt; 

void bfs(int start){

    q.push(start);

    while(!q.empty){
        int here = q.front;
        q.pop();

        //자식 노드가 비어있다면 -> 리프노드라면 
        if(tree[here].child.empty()){
            cnt++;
        }

        for(int i =0; i < tree[here].child.size(); i++){
            q.push(tree[here].child[i]);
        }
    }

}

