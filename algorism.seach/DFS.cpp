
#include <iostream>
#include <vector>

using namespace std;

int number = 7; 
int c[8];
vector<int> a[8];


void dfs(int x){

    if(c[x]) return;  //이미 방문한 노드라면 리턴함 

    c[x] = true;    //방문하지않았다면 방문표시함 

    cout << x << " " ; //그리고 출력함 

    for(int i = 0; i < a[x].size(); i++){ //입력받은 값의 모든 ~ 인접 노드를 돌면서~ 
        int y = a[x][i];

        dfs(y);

    }

}


int main (void){

    a[1].push_back(2);
    a[2].push_back(1);

    a[1].push_back(3);
    a[3].push_back(1);

    a[2].push_back(3);
    a[3].push_back(2);

    a[2].push_back(4);
    a[4].push_back(2);

    a[2].push_back(5);
    a[5].push_back(2);

    a[3].push_back(6);
    a[6].push_back(3);

    a[3].push_back(7);
    a[7].push_back(3);

    a[4].push_back(5);
    a[5].push_back(4);

    a[6].push_back(7);
    a[7].push_back(6);

    dfs(1);

    return 0;
}