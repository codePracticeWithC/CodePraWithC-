// 체스판은 8*8크기이고, 검정 칸과 하얀 칸이 번갈아가면서 색칠되어 있다. 
// 가장 왼쪽 위칸 (0,0)은 하얀색이다. 
// 체스판의 상태가 주어졌을 때, 하얀 칸 위에 말이 몇 개 있는지
//  출력하는 프로그램을 작성하시오.

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

 


void whiteBlock(vector<string> param){


    int a[8][8];
    int sum = 0;
    
    //합칠문자열 
    string str2; 

    //체스판을 검은색 흰색으로 색칠 
    for(int i = 0; i <= 7; i++){
        for (int j = 0; j <= 7; j++){
            
            if(i % 2 == 0 && j % 2 == 0){
                a[i][j] = 0;
            }else if(i % 2 == 1 && j % 2== 0){
                a[i][j] = 0;
            }else{
                a[i][j] = 1;
            }
        }
    }

    
    

    for(int i = 0; i <= 7; i++){

        for(int j = 0; j <=7; j++){
            if(a[i][j] == 0 && param[i].substr(j,1).compare("F") == 0){

                sum++;
            }

        }

    }

    cout << sum ;
  

}


int main(void){

    vector<string> sarr; 

    for(int i = 1; i <=8; i++){
        string data; 
        cin >> data;
        sarr.push_back(data);
    }

    whiteBlock(sarr);
    
}