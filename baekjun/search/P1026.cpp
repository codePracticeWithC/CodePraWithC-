
// 길이가 N인 정수 배열 A와 B가 있다. 다음과 같이 함수 S를 정의하자.

// S = A[0]*B[0] + ... + A[N-1]*B[N-1]

// S의 값을 가장 작게 만들기 위해 A의 수를 재배열하자. 
//단, B에 있는 수는 재배열하면 안 된다.

// S의 최솟값을 출력하는 프로그램을 작성하시오.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int number; //배열의 크기 

vector<int> a,b;


bool compare(int a, int b){
    return a > b;
}


void seacrhMin(){

    int min = 0; //최솟값 

    sort(a.begin(),a.end());

    sort(b.begin(),b.end(),compare);



    for(int i = 0; i < number; i++){
        min += a[i] * b[i];
    }

    printf("%d", min);

}



int main(void){


 cin >> number;

 for(int i = 1; i <= number; i++){

     int data;
     cin >> data; 

     a.push_back(data);
     
 }
 for(int i = 1; i <= number; i++){

     int data;
     cin >> data; 

     b.push_back(data);
     
 }


 seacrhMin();


}