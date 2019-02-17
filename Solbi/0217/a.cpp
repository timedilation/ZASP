#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int main(){

	int T, i, j;
	int row, column, k;
	int r_tmp, c_tmp;
	int arr [100][100];

	scanf("%d", &T);

	for(i = 0; i < T; i++){

		scanf("%d %d %d", &row, &column, &k);


		if(row * column - k == 1){
			printf("Case #%d: IMPOSSIBLE\n", i+1);
			continue;
		}

		r_tmp = row-1;
		c_tmp = column-1;
		while(k>0){
			
			arr[r_tmp][c_tmp]=4;
			c_tmp--;
			k--;

			if(c_tmp < 0){
				r_tmp--;
				c_tmp = column-1;
			}
		}
		if(c_tmp == 0){
			arr[r_tmp][c_tmp] = 1;
			r_tmp--;
			c_tmp = column-1;

		}

		while(r_tmp >= 0){

			if(c_tmp == 0){
				if(column==1){
					if(r_tmp == 0)
						arr[r_tmp][c_tmp] = 4;
					else
						arr[r_tmp][c_tmp] = 1;
				}
				else
					arr[r_tmp][c_tmp] = 2;
			}
			else{
				arr[r_tmp][c_tmp] = 3;
			}

			c_tmp--;

			if(c_tmp < 0){
				r_tmp--;
				c_tmp = column-1;
			}
		}

		printf("Case #%d: POSSIBLE\n", i+1);

		for(j = 0; j < row; j++){
			for(k=0; k< column; k++){
				if(arr[j][k] == 1){
					printf("N");
				}
				else if(arr[j][k] == 2){
					printf("E");
				}
				else if(arr[j][k] == 3){
					printf("W");
				}
				else if(arr[j][k] == 4){
					printf("S");
				}
			}
			printf("\n");
		}
		
	}

	return 0;
}