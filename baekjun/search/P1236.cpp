#include <iostream>


using namespace std;


int main(void) {

    int n,m;

    cin >> n >> m;


    char castle[55][55];

    for(int i = 0; i < n; i++) {
			
			for(int j = 0; j < m ; j++) {
				
				cin >> castle[i][j] ; 
			}
			
		}


    int count = 0;
		
		//가로 확인 
		for(int i = 0; i < n; i++) {
			
			bool flag = false; 
			
			for(int j = 0; j < m ; j++) {
				//경비원이 있으면 탈출 
			
				if(castle[i][j] == 'X') {
					flag = true;
					break;
				}
					
			}
			
			if(flag == false) {
				count++;
			}
			
		}
		
		int count2 = 0;
		
		

		//세로 확인 
		for(int j = 0; j < m; j++) {
		
			bool flag = false; 
			
			for(int i = 0; i < n ; i++) {
				//경비원이 있으면 탈출 
			
				if(castle[i][j] == 'X') {
					flag = true;
					break;
				}
					
			}
			
			if(flag == false) {
				count2++;
			}
			
		}
		
		
		
		
		
		if(count > count2) {
			cout << count;
		}else {
			cout << count2;
		}

    return 0;
}