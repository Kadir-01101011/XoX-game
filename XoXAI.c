#include <stdio.h>
#include <stdlib.h>

char room[9];

void print_table() {    // function that prints the table on which game is played
  printf(" %c | %c | %c \n", room[0], room[1], room[2]);
  printf("-----------\n");
  printf(" %c | %c | %c \n", room[3], room[4], room[5]);
  printf("-----------\n");
  printf(" %c | %c | %c \n", room[6], room[7], room[8]);
}

void machine() {
  int place;
  
  // TODO: AI
  place = 4;
  
  room[place] = 'O';
}

void play() {  // function that takes and returns the area of the next move
    int num = 0;
    printf("Which room you're gonna type on?_");
    scanf("%d", &num);
    
    if (num <= 9 && num >= 1 && room[num-1] == ' ') {
        room[num-1] = 'X';
    }
    else {
        printf("\nType a number between 1-9 whose room is empty.\n");
        play();
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
            
        system("clear");
        printf("Player is the winner!\n");
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
            
        system("clear");
        printf("Machine is the winner!\n");
        return 1;
    }
    else    return 0;
}

int main() {
        
    for (int n = 0; n < 9; n++) {
        room[n] = ' ';
    }
    
    for (int i = 0; i < 9; i++) {
        system("clear");
        print_table();
      
        play();
        if (is_finished() == 1) break;
        
        machine();
        if (is_finished() == 1) break;
      
    }
  
    print_table();
    
    return 0;
    
}
