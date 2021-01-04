#include <iostream>

using namespace std;
char room[9];
char player[2] = {'X', 'O'};

void print_table() {
    cout << " " << room[0] << " | " << room[1] << " | " << room[2] << endl;
    cout << "-----------" << endl;
    cout << " " << room[3] << " | " << room[4] << " | " << room[5] << endl;
    cout << "-----------" << endl;
    cout << " " << room[6] << " | " << room[7] << " | " << room[8] << endl;
}

void play(int order) {
    int num = 0;
    cout << "Which room you are going to type on? ";
    cin >> num;
    
    if(num <= 9 && num >=0 && room[num-1] == ' ') {
        if(order == 0)  room[num-1] = 'X';
        else            room[num-1] = 'O';
    }
    else {
        cout << "\nType a number between 1-9 whose room is empty" << endl;
        play(order);
    }
}

bool is_finished() {
    if(room[0] == room[1] && room[0] == room[2] && room[0] == 'X' ||   // horizontal
        room[3] == room[4] && room[3] == room[5] && room[3] == 'X' ||   
        room[6] == room[7] && room[6] == room[8] && room[6] == 'X' ||
        room[0] == room[3] && room[0] == room[6] && room[0] == 'X' ||   // vertical
        room[1] == room[4] && room[1] == room[7] && room[1] == 'X' ||
        room[2] == room[5] && room[2] == room[8] && room[2] == 'X' ||
        room[0] == room[4] && room[0] == room[8] && room[0] == 'X' ||   // cross
        room[2] == room[4] && room[2] == room[6] && room[2] == 'X') {
        
        cout << "Player 1 (X) is the winner!" << endl;    
        return true;
    }
    else if (room[0] == room[1] && room[0] == room[2] && room[0] == 'O' ||  // horizontal
            room[3] == room[4] && room[3] == room[5] && room[3] == 'O' ||
            room[6] == room[7] && room[6] == room[8] && room[6] == 'O' ||   
            room[0] == room[3] && room[0] == room[6] && room[0] == 'O' ||   // vertical
            room[1] == room[4] && room[1] == room[7] && room[1] == 'O' ||
            room[2] == room[5] && room[2] == room[8] && room[2] == 'O' ||
            room[0] == room[4] && room[0] == room[8] && room[0] == 'O' ||   // cross
            room[2] == room[4] && room[2] == room[6] && room[2] == 'O') {
            
        cout << "Player 2 (O) is the winner!" << endl;
        return true;
    }
    else    return false;
}

int main() {
    for(int i = 0; i < 9; i++)
        room[i] = ' ';
    
    print_table();
    
    for(int i = 0; i < 9; i++) {
        int turn = i%2;
        cout << player[turn] << " is playing;\n";
        
        play(turn);
        
        system("clear");
        print_table();
        
        if(i > 3) {
            if(is_finished() == true) {
                return 0;
            }
        }
    }
    cout << "No winner! Let's play one more.\n";

    
    return 0;
}
