#include <stdio.h>

#define COLUMN 11
#define ROW 5

void how_to_play() {// function that prints the information about gameplay
    
    printf(" 1 | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 \n\n");
    printf("Type the area u want to play when it's your turn\n");
    printf("Player 1: X, Player 2: O\n\n");
    
}

void print_table(char table[ROW][COLUMN]) {    // function that prints the table on which game is played
  
  for (int i = 0; i < ROW; i++) {
    for (int n = 0; n < COLUMN; n++) {
      printf("%c", table[i][n]);
    }
  printf("\n");
  }
}

int which_room() {
    int num = 0;
    printf("which room you're gonna type on?_");
    scanf("%d", &num);
    return num;
}

void move_x (int index, char (*ptrX)[ROW][COLUMN]) {
    if (index == 1)         *(*(ptrX+0)+2) = 'X';
    else if (index == 2)    *(*(ptrX+0)+6) = 'X';
    else if (index == 3)    *(*(ptrX+0)+10) = 'X';
    else if (index == 4)    *(*(ptrX+3)+2) = 'X';
    else if (index == 5)    *(*(ptrX+3)+6) = 'X';
    else if (index == 6)    *(*(ptrX+3)+10) = 'X';
    else if (index == 7)    *(*(ptrX+5)+2) = 'X';
    else if (index == 8)    *(*(ptrX+5)+6) = 'X';
    else if (index == 9)    *(*(ptrX+5)+10) = 'X';
}

void move_O (int index, char *ptrO[ROW][COLUMN]) {
    if (index == 1)         *(*(ptrO+0)+2) = 'O';
    else if (index == 2)    *(*(ptrO+0)+6) = 'O';
    else if (index == 3)    *(*(ptrO+0)+10) = 'O';
    else if (index == 4)    *(*(ptrO+3)+2) = 'O';
    else if (index == 5)    *(*(ptrO+3)+6) = 'O';
    else if (index == 6)    *(*(ptrO+3)+10) = 'O';
    else if (index == 7)    *(*(ptrO+5)+2) = 'O';
    else if (index == 8)    *(*(ptrO+5)+6) = 'O';
    else if (index == 9)    *(*(ptrO+5)+10) = 'O';
}


int main() {
    
    how_to_play();
    
    int k, m;
    char pattern[ROW][COLUMN];
    
    for(k = 0; k < ROW; k++) {
        for(m = 0; m < COLUMN; m++) {
            if (k % 2 != 0)
                pattern[k][m] = '-';
            else if (k % 2 == 0 && (m == 3 || m == 7)) 
                pattern[k][m] = '|';
            else
                pattern[k][m] = ' ';
        }
    }
    
  //  char (*patternptr) = &pattern;

    for (int order = 0; order < 9; order++) {
        int turn = (order % 2) + 1;
        printf("Player %d's turn: \n", turn);
        if (turn ==1)   move_X(which_room, &pattern);
        else            move_O(which_room, &pattern);
        
        print_table(pattern);
    }
    
    return 0;
    
}
