#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;




int main(void){


    int n, k;

    cin >> n >> k;

    

     int coin[10];


     for(int i = 0; i < n; i++){
        cin >> coin[i];
     }

    int result = 0;
    int namuji = 0;

    sort(coin, coin + n, greater<int>());
   
    
    result += k / coin[0];
    namuji = k % coin[0];

    for(int i = 1; i < n; i++){

        if(namuji == 0) break;


        result += namuji / coin[i];
        namuji =  namuji % coin[i];

    }
 
    
  
    printf("%d", result);


    return 0;
}