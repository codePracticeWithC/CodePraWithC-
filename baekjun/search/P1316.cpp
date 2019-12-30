
// 그룹 단어란 단어에 존재하는 모든 문자에 대해서, 
// 각 문자가 연속해서 나타나는 경우만을 말한다. 예를 들면, 
// ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고,
//  kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, 
//  aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.

// 단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.


#include <iostream>

using namespace std;

int count = 0;

void wordChecker(string str){

    for(int i = 0; i < str.size(); i++){

        if(str[i] != str[i+1]){

            for(int j = i+2; j < str.size(); j++){

                if(str[i] == str[j])
                return ;

            }


        }

    }

      count++;


}



int main(void){

    int n; 
    cin >> n; 

    for(int i = 1; i <= n; i++){
        string str; 

        cin >> str; 

        wordChecker(str);

    }


    printf("%d",count);

}