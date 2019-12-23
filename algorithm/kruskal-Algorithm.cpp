
//Kruskal-Algorithm 크루스칼 알고리즘 
//가장 적은 비용으로 모든 노드를 연결하기 위해 사용하는 알고리즘 (최소 비용 신장트리를 만드는 알고리즘)
//여러개의 도시가 있을 때 각 도시를 도로를 이용해 연결하고자 한다면 그 최소 비용을 계산할때 
//실제로 적용되는 알고리즘임 

//노드 = 정점 = 도시 
//간선 = 거리 = 비용 

//간선을 거리가 짧은 순서대로 그래프에 포함시키면 어떨까? 
//모든 간선정보를 오름차순 정렬 뒤 가장 적은 비용으로 모든 노드를 연결함 

//1. 정렬된 순서에 맞게 그래프에 포함함.
//2. 포함시키기 전에 사이클 테이블을 확인함.
//3. 사이클을 형성하는 경우에는 간선에 포함시키지 않음 

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


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


//간선 정보를 갖는 간선클래스 선언 

class Edge{
    public : int node[2]; //간선에 연결되어있는 두개의 노드 
    public : int distance; //비용 

    Edge(int a, int b, int distance){
        this -> node[0] = a;
        this -> node[1] = b;
        this -> distance = distance;
    }


    //매개변수랑 현재 변수랑 비교해서 distance가 낮은 순으로 정렬되게 할것임 
    bool operator <(Edge &edge) {
        return this -> distance < edge.distance;
    }

};


int main(void){

     int n = 7; //노드는 7개 
     int m = 11; //간선은 11개 

     vector<Edge> v;

     //예제 대로 그래프 만들어주기 
     v.push_back(Edge(1,7,12));
     v.push_back(Edge(1,4,28));
     v.push_back(Edge(1,2,67));
     v.push_back(Edge(1,5,17));
     v.push_back(Edge(2,4,24));
     v.push_back(Edge(2,5,62));
     v.push_back(Edge(3,5,20));
     v.push_back(Edge(3,6,37));
     v.push_back(Edge(4,7,13));
     v.push_back(Edge(5,6,45));
     v.push_back(Edge(5,7,73));


    //간선의 기준으로 오름차순 정렬함 
    sort(v.begin(), v.end());

    
    //각 정점이 포함된 그래프가 어디인지 저장함 Union-Find
    //모든 정점은 자신을 가르키도록 함 
    int parent[n];
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }

    int sum = 0; //비용의 합 
    for(int i = 0; i < v.size(); i++){

        //사이클이 발생하지 않는 경우 그래프에 포함한다 
        //예를 들어 1,7 이 같은 노드를 부모로 갖게되면 그건 싸이클임
       

        if(!findParent(parent,v[i].node[0]-1, v[i].node[1]-1)){
            sum += v[i].distance;

            //노드 2개를 그래프에 합쳐준다 
            unionParent(parent,v[i].node[0]-1,v[i].node[1]-1);
        }

    }

    //최소비용 출력 
    printf("%d\n",sum);

}