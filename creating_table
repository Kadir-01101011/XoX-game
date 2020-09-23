// decleration and initialization of game table on string[][] base

#include <stdio.h>

void create_table() {
    
    int k, m;
    char pattern[5][11];
    
    for(k = 0; k < 5; k++) {
        for(m = 0; m < 11; m++) {
            if (k % 2 != 0)
                pattern[k][m] = '-';
            else if (k % 2 == 0 && (m == 3 || m == 7)) 
                pattern[k][m] = '|';
            else
                pattern[k][m] = ' ';
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int n = 0; n < 11; n++)
            printf("%c", pattern[i][n]);
        printf("\n");
    }
    
}
