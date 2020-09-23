#include <stdio.h>

#define COLUMN 11
#define ROW 5

void how_to_play() {// function that prints the information about gameplay
    
    printf(" 1 | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 \n\n");
    printf("Type the area first, then type X or O\n\n");
    
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

void move_x(int index, char *ptrX) {
    if (index == 1)         (*ptrX)[0][2] = 'X';
    else if (index == 2)    (*ptrX)[0][4] = 'X';
    else if (index == 3)    (*ptrX)[0][10] = 'X';
    else if (index == 4)    (*ptrX)[2][2] = 'X';
    else if (index == 5)    (*ptrX)[2][4] = 'X';
    else if (index == 6)    (*ptrX)[2][10] = 'X';
    else if (index == 7)    (*ptrX)[4][2] = 'X';
    else if (index == 8)    (*ptrX)[4][4] = 'X';
    else if (index == 9)    (*ptrX)[4][10] = 'X';
}

void move_O(int index, char *ptrO) {
    if (index == 1)         (*ptrO)[0][2] = 'O';
    else if (index == 2)    (*ptrO)[0][4] = 'O';
    else if (index == 3)    (*ptrO)[0][10] = 'O';
    else if (index == 4)    (*ptrO)[2][2] = 'O';
    else if (index == 5)    (*ptrO)[2][4] = 'O';
    else if (index == 6)    (*ptrO)[2][10] = 'O';
    else if (index == 7)    (*ptrO)[4][2] = 'O';
    else if (index == 8)    (*ptrO)[4][4] = 'O';
    else if (index == 9)    (*ptrO)[4][10] = 'O';
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
    
    char (*patternptr)[ROW][COLUMN] = &pattern;

    for (int order = 0; order < 9; order++) {
        int turn = (order % 2) + 1;
        printf("Player %d's turn: \n", turn);
        if (turn ==1)   move_X(which_room, *patternptr);
        else            move_O(which_room, *patternptr);
        
        print_table(pattern);
    }
    
    return 0;
    
}
