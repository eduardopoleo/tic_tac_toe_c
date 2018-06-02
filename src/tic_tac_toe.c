/*
 ============================================================================
 Name        : tic_tac_toe.c
 Author      : eduardo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int board_state[9];

void readln(char s[], int maxlen) {
	char ch;
	int i = 0;
	int chars_remaining = 1;

	while (chars_remaining) {
		ch = getchar();
		// the main take away here is that the loop only stops when
		// we've completely flushed the input.
		if (ch == '\n' || ch == EOF) {
			chars_remaining = 0;
		// why maxlen - 1? works. Well cuz we need one space for \0
		} else if (i < maxlen - 1) {
			s[i] = ch;
			i++;
		}
	}

	s[i] = '\0';
}

#define MOVE_LENGTH 3

int getmove() {
	// Even if it's only 1 character we need: input, \n, \0 => 3
	char move_input[MOVE_LENGTH];
	int move;
	printf("Enter your move (1-9): ");
//	TODO makes this secure
// 	Make sure it's an integer between 1 - 9
//  longer/shorter strings won't break the program
	readln(move_input, MOVE_LENGTH);

	move = atoi(move_input);
	int validated_move = validate_move(move);
	return validated_move;
}

int validate_move(int move) {
	int valid_moves[] = {1,2,3,4,5,6,7,8,9};

	for(int i = 0; i < 9; i++) {
		if (valid_moves[i] == move && board_state[move - 1] == 0) {
			return move;
		}
	}

	return 0;
}

void update_board_state(int symbol, int move) {
	// zero base
	move = move - 1;
	board_state[move] = symbol;
}

void print_board() {
	char board_state_symbol[9];
	char curent_move_symbol;
	int board_size = sizeof(board_state) / sizeof(board_state[0]);

	for (int i = 0; i < board_size; i++) {
		switch(board_state[i]) {
		   case 1  :
			  curent_move_symbol = 'X';
		      break;
		   case -1  :
			  curent_move_symbol = 'O';
		      break;
		   default :
			  curent_move_symbol = ' ';
		}

		board_state_symbol[i] = curent_move_symbol;
	}

	printf(" %c | %c | %c \n", board_state_symbol[0], board_state_symbol[1], board_state_symbol[2]);
	printf("___|___|___\n");
	printf(" %c | %c | %c \n", board_state_symbol[3], board_state_symbol[4], board_state_symbol[5]);
	printf("___|___|___\n");
	printf(" %c | %c | %c \n", board_state_symbol[6], board_state_symbol[7], board_state_symbol[8]);
	printf("   |   |   \n");
}

void initialize_board() {
	int board_size = sizeof(board_state) / sizeof(board_state[0]);

	for (int i = 0; i < board_size; i++) {
		board_state[i] = 0;
	}

}

int game_won() {
	int at_0 = board_state[0];
	int at_1 = board_state[1];
	int at_2 = board_state[2];
	int at_3 = board_state[3];
	int at_4 = board_state[4];
	int at_5 = board_state[5];
	int at_6 = board_state[6];
	int at_7 = board_state[7];
	int at_8 = board_state[8];

	if(at_0 == at_1 && at_0 == at_2) {
		if (at_0 != 0) {
			return 1;
		}
	} else if(at_0 == at_3 && at_0 == at_6) {
		if (at_0 != 0) {
			return 1;
		}
	} else if(at_0 == at_4 && at_0 == at_8) {
		if (at_0 != 0) {
			return 1;
		}
	} else if(at_1 == at_4 && at_1 == at_7) {
		if (at_1 != 0) {
			return 1;
		}
	} else if(at_2 == at_5 && at_2 == at_8) {
		if (at_2 != 0) {
			return 1;
		}
	} else if(at_2 == at_4 && at_2 == at_6) {
		if (at_2 != 0) {
			return 1;
		}
	} else if(at_3 == at_4 && at_3 == at_5) {
		if (at_3 != 0) {
			return 1;
		}
	} else if(at_6 == at_7 && at_6 == at_8) {
		if (at_6 != 0) {
			return 1;
		}
	}

	return 0;
}

int main(int argc, char **argv) {
	int move;
	// X = 1, O = 0
	int symbol = 1;
	initialize_board();

	int board_size = sizeof(board_state) / sizeof(board_state[0]);

	// TODO this is too naive and assumes that the input is always correct
	// make the get move to somehow return if the input is correct or not. e.g -1
	int count = 0;
	while (count < board_size) {
		print_board();
		move = getmove();

		if (move != 0) {
			update_board_state(symbol, move);

			if (game_won() == 1) {
				break;
			}

			if (symbol == 1) {
				symbol = -1;
			} else {
				symbol = 1;
			}

			count++;
		} else {
			printf("Please enter a valid move\n");
		}

	}

	print_board();

	return 0;
}
