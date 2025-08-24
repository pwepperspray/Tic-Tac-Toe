/*
A simple console Tic-Tac-Toe game in C.
Author : cinnamon_rowll
Github : @pwepperspray
*/

//NOTE : In user defined functions of int return value, 0 is false and 1 is true.

#include <stdio.h>
#include <conio.h>

void set_up_grid();
void display();
void clear_screen();
void run_game(char p1, char p2);
int insert(int x, int y, char val);
int check_win(char player_symbol);
int is_grid_full();

char grid[3][3];

int main(){
    char p1, p2, choice;
    //-------------menu-------------//
    while(1){
        clear_screen();
        printf("Tic Tac Toe game! \nInput C to exit. \n");
        printf("Select which will start first : X or O \n>>");
        scanf(" %c", &choice);

        if(choice == 'x' || choice == 'X'){
            p1 = 'X';
            p2 = 'O';
            run_game(p1,p2);
        }else if(choice == 'o' || choice == 'O'){
            p1 = 'O';
            p2 = 'X';
            run_game(p1,p2);
        }else if(choice == 'c' || choice == 'C'){
            printf("Thanks For Playing!");
            break;
        }else{
            printf("Enter a valid value");
        }
    }
    return 0;
}


void set_up_grid(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j <3; j++){
            grid[i][j] = ' ';
        }
    }
}

void display(){
    for(int i = 0; i < 3; i++){
        printf("%3c%3c%3c%3c%3c\n", grid[i][0], '|', grid[i][1], '|', grid[i][2]);
        if(i < 2){
            printf("-----------------\n");
        } 
    }
}

void clear_screen(){
    printf("\e[1;1H\e[2J"); 
}
	
void run_game(char p1, char p2){
    int x,y;

    set_up_grid();
    clear_screen();

    while(1){
        //Player 1 turn
        while(1){
            display();
            printf("Player %c enter coordinate : ", p1);
            scanf("%d %d", &x,&y);
            if(x <= 3 && x > 0 && y <= 3 && y > 0){
                if(insert(x,y,p1)){
                    break;
                }
            }else{
                printf("Enter a valid value\n");
            }     
        }

        if(check_win(p1)){
            printf("Player %c has Won!", p1);
            getch();
            break;
        }

        if(is_grid_full()){
            printf("Grid is full! NOBODY WINS!");
            getch();
            break;
        }

        clear_screen();

        //Player 2 turn    
        while(1){
            display();
            printf("Player %c enter coordinate : ", p2);
            scanf("%d %d", &x,&y);
            if(x <= 3 && x > 0 && y <= 3 && y > 0){
                if(insert(x,y,p2)){
                    break;
                }
            }else{
                printf("Enter a valid value\n");
            }
        }

        if(check_win(p2)){
            printf("Player %c has Won!", p1);
            getch();
            break;
        }

        if(is_grid_full()){
            printf("Grid is full! NOBODY WINS!");
            getch();
            break;
        }

        clear_screen();
    }
}

int insert(int x, int y, char val){
	if(grid[x - 1][y -1] == ' '){
        grid[x - 1][y - 1] = val;
        return 1;
    }else{
        printf("Enter an Empty cell coordinate \n");
    }
    return 0;
}

int check_win(char player_symbol){
   //Row check
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == player_symbol && grid[i][1] == player_symbol && grid[i][2] == player_symbol) {
            return 1; // Win
        }
    }
    //Column Check
    for (int j = 0; j < 3; j++) {
        if (grid[0][j] == player_symbol && grid[1][j] == player_symbol && grid[2][j] == player_symbol) {
            return 1; // Win
        }
    }
    //diagonal Check
    if ((grid[0][0] == player_symbol && grid[1][1] == player_symbol && grid[2][2] == player_symbol) ||
        (grid[0][2] == player_symbol && grid[1][1] == player_symbol && grid[2][0] == player_symbol)) {
        return 1; // Win
    }

    return 0;
}

int is_grid_full(){
    int count = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i][j] != ' '){
                count++;
            }
        }
    }

    if(count < 9){
        return 1;
    }

    return 0;
}

