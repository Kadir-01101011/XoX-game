#include <stdio.h>
#include <stdlib.h>

char room[9];

void how_to_play() {    // function that prints the information about gameplay
    printf(" 1 | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 \n\n");
    printf("Type the room you want to play when it's your turn\n");
    printf("You can only type on a room that is empty.\n");
    printf("Player 1: X, Player 2: O\n\n");
}

void print_table() {    // function that prints the table on which game is played
  printf(" %c | %c | %c \n", room[0], room[1], room[2]);
  printf("-----------\n");
  printf(" %c | %c | %c \n", room[3], room[4], room[5]);
  printf("-----------\n");
  printf(" %c | %c | %c \n", room[6], room[7], room[8]);
}

void play(int order) {  // function that takes and returns the area of the next move
    int num = 0;
    printf("Which room you're gonna type on?_");
    scanf("%d", &num);
    
    if (num <= 9 && num >= 1 && room[num-1] == ' ') {
        if(order == 1)    room[num-1] = 'X';
        else              room[num-1] = 'O';
    }
    else {
        printf("\nType a number between 1-9 whose room is empty.\n");
        pleay(order);
    }
}

int is_finished() {
    if (room[0] == room[1] && room[0] == room[2] && room[0] == 'X' ||   // horizontal
        room[3] == room[4] && room[3] == room[5] && room[3] == 'X' ||   
        room[6] == room[7] && room[6] == room[8] && room[6] == 'X' ||
        room[0] == room[3] && room[0] == room[6] && room[0] == 'X' ||   // vertical
        room[1] == room[4] && room[1] == room[7] && room[1] == 'X' ||
        room[2] == room[5] && room[2] == room[8] && room[2] == 'X' ||
        room[0] == room[4] && room[0] == room[8] && room[0] == 'X' ||   // cross
        room[2] == room[4] && room[2] == room[6] && room[2] == 'X') {
            
        printf("Player 1 is the winner!\n");
        return 1;
    }
    else if (room[0] == room[1] && room[0] == room[2] && room[0] == 'O' ||  // horizontal
            room[3] == room[4] && room[3] == room[5] && room[3] == 'O' ||
            room[6] == room[7] && room[6] == room[8] && room[6] == 'O' ||   
            room[0] == room[3] && room[0] == room[6] && room[0] == 'O' ||   // vertical
            room[1] == room[4] && room[1] == room[7] && room[1] == 'O' ||
            room[2] == room[5] && room[2] == room[8] && room[2] == 'O' ||
            room[0] == room[4] && room[0] == room[8] && room[0] == 'O' ||   // cross
            room[2] == room[4] && room[2] == room[6] && room[2] == 'O') {
            
        printf("Player 2 is the winner!\n");
        return 1;
    }
    else    return 0;
}

int main() {
        
    for (int n = 0; n < 9; n++) {
        room[n] = ' ';
    }
    
    for (int i = 0; i < 9; i++) {
        int turn = (i % 2) + 1;
        printf("Player %d's turn: \n", turn);
        play(turn);
        
        system("clear");
        print_table();
        
        if (order > 3) {
            if (is_finished() == 1) {                
                printf("Congrats to the winner.\n");
                return 0;
            }       
        }
    }
    
    return 0;
    
}
