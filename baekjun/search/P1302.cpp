




#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


int main(void){

    int n;

    scanf("%d" , &n);

    vector<string> v;
    vector<string> result;
    
    int count[1001];

    //배열에 입력받음 
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;

        v.push_back(str);

    }

    
    

    return 0;
}