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

    // 

    print_table(pattern);
    
    return 0;
    
}
