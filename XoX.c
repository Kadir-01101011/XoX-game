#include <stdio.h>

char move[9];

void how_to_play() {// function that prints the information about gameplay
    
    printf(" 1 | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 \n\n");
    printf("Type the room you want to play when it's your turn\n");
    printf("You can only type on a room that is empty.\n");
    printf("Player 1: X, Player 2: O\n\n");
}

void print_table() {    // function that prints the table on which game is played
  
  printf(" %c | %c | %c \n", move[0], move[1], move[2]);
  printf("-----------\n");
  printf(" %c | %c | %c \n", move[3], move[4], move[5]);
  printf("-----------\n");
  printf(" %c | %c | %c \n", move[6], move[7], move[8]);
  
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
    if (move[index-1] == ' ')
        move[index-1] = 'X';
    else {
        printf("You can't type upon your friends room. Please try again.\n");
        move_X(which_room());
    }
}

void move_O (int index) {
    if (move[index-1] == ' ')
        move[index-1] = 'O';
    else {
        printf("You can't type upon your friends room.Please try again.\n");
        move_O(which_room());
    }
}


int main() {
    
    how_to_play();
    
    for (int n = 0; n < 9; n++) {
        move[n] = ' ';
    }
    for (int order = 0; order < 9; order++) {
        int turn = (order % 2) + 1;
        printf("Player %d's turn: \n", turn);
        if (turn ==1)   move_X(which_room());
        else            move_O(which_room());
        
        print_table();
    }
    
    return 0;
    
}
