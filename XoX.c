#include <stdio.h>
#include <stdlib.h>

char room[9];

void how_to_play() {// function that prints the information about gameplay
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

int which_room() {  // function that takes and returns the area of the next move
    int num = 0;
    printf("Which room you're gonna type on?_");
    scanf("%d", &num);
    
    if (num <= 9 && num >= 1)
        return num;
    else {
        printf("\nType a number between 1-9");
        which_room();
    }
}

void move_X (int index) {
    if (room[index-1] == ' ')
        room[index-1] = 'X';
    else {
        printf("You can't type upon your friends room. Please try again.\n");
        move_X(which_room());
    }
}

void move_O (int index) { // will be AI
    if (room[index-1] == ' ')
        room[index-1] = 'O';
    else {
        printf("You can't type upon your friends room. Please try again.\n");
        move_O(which_room());
    }
}


int main() {
    
    how_to_play();
    
    for (int n = 0; n < 9; n++) {
        room[n] = ' ';
    }
    
    for (int order = 0; order < 9; order++) {
        int turn = (order % 2) + 1;
        printf("Player %d's turn: \n", turn);
        if (turn ==1)   move_X(which_room());
        else            move_O(which_room());
        
        system("clear");
        how_to_play();
        print_table();
    }
    
    return 0;
    
}
