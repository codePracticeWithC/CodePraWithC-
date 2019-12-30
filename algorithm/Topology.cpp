

//위상정렬 알고리즘 
//진입차수 -> 해당 노드로 들어오는 개수를 의미함 

//1. 진입차수가 0인정점을 큐에 삽입함
//2. 큐에서 원소를 꺼내 연결된 모든 간선을 제거함 
//3. 간선 제거 이후에 진입차수가 0이된 정점을 큐에 삽입함 
//4. 큐가 빌때까지 2,3번 과정을 반복, 모든 원소를 방문하기전에 큐가 빈다면 
// 사이클이 존재하는것이고, 모든 원소를 방문했다면 큐에서 꺼낸 순서가
//곧 위상 정렬의 결과임 


#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

//정점과 진입차수 
int n, inDegree[MAX]; 

vector<int> a[MAX];

void topology(){

    int result[MAX];
    queue<int> q;

    //진입차수가 0인노드를 큐에 삽입
    for(int i = 1; i <= n; i++){
        if(inDegree[i] == 0)
            q.push(i);
    }

    //위상 정렬이 수행되려면 정확히 N개의 노드를 방문해야함 
    for(int i = 1; i <= n; i++){
        //큐가 비어버리면 사이클이 발생한것임 
        if(q.empty()){
            printf("사이클이 발생했습니다");
            return;
        }

        //큐에 제일 앞에있는 원소를 빼서 결과배열에 담는다 
        int x  = q.front();
        q.pop();
        result[i] = x;
        //인접한 모든노드의 간선을 제거함 
        for(int i = 0; i < a[x].size(); i++){
            int y = a[x][i];

            inDegree[y]--;
            
            if(inDegree[y] == 0) 
                q.push(y);
        }


    }

    for(int i = 1; i <= n ; i++){
        printf("%d ", result[i]);
    }



}





int main(void){
    
    n = 7; 
    a[1].push_back(2);
    inDegree[2]++;
    a[1].push_back(5);
    inDegree[5]++;
    a[2].push_back(3);
    inDegree[3]++;
    a[3].push_back(4);
    inDegree[4]++;
    a[4].push_back(6);
    inDegree[6]++;
    a[5].push_back(6);
    inDegree[6]++;
    a[6].push_back(7);
    inDegree[7]++;

    topology();
    

}