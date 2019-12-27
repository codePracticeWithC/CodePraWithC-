
/* 
        1
     /  ┃   \ 
    3   ┃    7
   /    ┃     \
  ⑵    6    (4)
   \    ┃     /
    1   ┃    1 
     \     / 
       (3) 
  
  모든 노드를 방문하는 최단거리를 찾는 알고리즘 
  최초에 1에서 3으로 가는 비용을 생각해본다, 당장 직선 비용이 6이 있다 

  그런데 1에서 2를 거쳐서 3으로 가는 경우 비용이 4 여서, 비용이 6 -> 4로 갱신된다 
  다익스트라 알고리즘은 현재까지 알고 있던 최단경로를 계속해서 갱신함 

  1. 출발 점을 설정함 
  2. 출발 점을 기준으로 각 노드의 최소 비용을 저장함 
  3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드를 선택함 
  4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용을 갱신함 
  5. 3번, 4번을 반복함 

*/

#include <iostream>
#include <vector>
#include <queue> //우선순위 큐는 힙구조와 같이 동작함 
 
using namespace std;

int number = 6;
//현재 바로 이어지지 않은 거리들은 무한대로 표현함  
int INF = 100000000;

vector<pair<int,int>> graph[7]; //간선 정보 

int dis[7]; //최소 비용 배열 

void dijkstra(int start){
    
    dis[start] = 0;
    priority_queue<pair<int,int>> pq; //힙 구조 유지

    while(!pq.empty()){
        //현재 방문하고자 하는 노드는 큐의 최상단 노드 
        int current = pq.top().first;
        //짧은 것이 먼저오도록 음수화 함  (원래 pq는  큰것이 먼저옴)
        int distance = -pq.top().second;

        pq.pop(); 
        //최단거리가 아닌 경우 무시함 
        if(dis[current] < distance) continue;

        for(int i = 0;  i < graph[current].size(); i++){
            //선택된 노드의 인접 노드 
            int next = graph[current][i].first;
            //선택된 노드를 거쳐서 인접 노드로 가는 비용 
            int nextDistance = distance + graph[current][i].second;

            if(nextDistance < dis[next]){ 
                dis[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
            }
        }

    }

}


int main (void){

    for(int i = 1; i <= number; i++){
        dis[i] = INF;
    }

    graph[1].push_back(make_pair(2,2));
    graph[1].push_back(make_pair(3,5));
    graph[1].push_back(make_pair(4,1));

    graph[2].push_back(make_pair(2,2));
    graph[2].push_back(make_pair(3,3));
    graph[2].push_back(make_pair(4,2));

    graph[3].push_back(make_pair(1,5));
    graph[3].push_back(make_pair(2,3));
    graph[3].push_back(make_pair(4,3));
    graph[3].push_back(make_pair(5,1));
    graph[3].push_back(make_pair(6,5));


    graph[4].push_back(make_pair(1,1));
    graph[4].push_back(make_pair(2,2));
    graph[4].push_back(make_pair(3,3));
    graph[4].push_back(make_pair(5,1));

    graph[5].push_back(make_pair(3,1));
    graph[5].push_back(make_pair(4,1));
    graph[5].push_back(make_pair(6,2));


    graph[6].push_back(make_pair(3,5));
    graph[6].push_back(make_pair(5,2));


    dijkstra(1);

    for(int i =1; i <= number; i++){
        printf("%d ",dis[i]);
    }

    return 0;
}





