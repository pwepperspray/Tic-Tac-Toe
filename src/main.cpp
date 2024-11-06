#include <stdio.h>

int main(){
	int x,y,state,count = 1, run = 0;
	char arr[3][3] = {{' ',' ',' '},
		          {' ',' ',' '},
			  {' ',' ',' '}};

	printf("Tic-Tac-Toe Game\n\n");
	for(int i = 0; i < 3; i++){
		printf("%3c%3c%3c%3c%3c\n", arr[i][0], '|', arr[i][1], '|', arr[i][2]);
		if(i < 2){
			printf("-----------------\n");
		} 
	}

	while(count < 10){	
		//input block
		printf("\nPlayer X enter coordinates : ");
		scanf("%d%d", &x, &y);
		if(arr[x - 1][y - 1] == ' '){
		arr[x - 1][y - 1] = 'X';
			count++;
		}
		else{
			printf("Enter Coordinate of empty spaces\n");
		}	

		for(int i = 0; i < 3; i++){
			printf("%3c%3c%3c%3c%3c\n", arr[i][0], '|', arr[i][1], '|', arr[i][2]);
			if(i < 2){
				printf("-----------------\n");
			} 
		}

		printf("\nPlayer O enter coordinates : ");
		scanf("%d%d", &x, &y);
		if(arr[x - 1][y - 1] == ' '){
			arr[x - 1][y - 1] = 'O';
			count++;
		}
		else{
			printf("Enter Coordinate of empty spaces\n");
		}	

		for(int i = 0; i < 3; i++){
			printf("%3c%3c%3c%3c%3c\n", arr[i][0], '|', arr[i][1], '|', arr[i][2]);
			if(i < 2){
				printf("-----------------\n");
			} 
		}

		/*************************************check block*********************************/
		//if rows match
		for(int i = 0; i < 3; i++){
			if(arr[i][0] != ' ' && arr[i][1] != ' ' && arr[i][2] != ' '){
				if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]){
					printf("%c Won!\n", arr[i][0]);
					count = 11;
				}
			}
		}

		//if columns match
		for(int i = 0; i < 3; i++){
			if(arr[0][i] != ' ' && arr[1][i] != ' ' && arr[2][i] != ' '){
				if(arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]){
					printf("%c Won!\n", arr[0][i]);
					count = 11;
				}
			}
		}

		//if first diagonal matches
		if(arr[0][0] != ' ' && arr[1][1] != ' ' && arr[2][2] != ' '){
			if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]){
				printf("%c Won!\n", arr[1][1]);
				break;
			}
		}

		//if second diagonal matches
		if(arr[0][2] != ' ' && arr[1][1] != ' ' && arr[2][0] != ' '){
			if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]){
				printf("%c Won!\n", arr[1][1]);
				break;
			}
		}
	}
	if(count == 9){
		printf("No one won \n");
	}

	return 0;
}


