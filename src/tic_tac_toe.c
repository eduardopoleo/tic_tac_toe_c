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

int getmove() {
	char move_input[5];
	int move;
	printf("Enter your move (1-9): ");
//	TODO makes this secure
// 	Make sure it's an integer between 1 - 9
//  longer/shorter strings won't break the program
	fgets(move_input, 5, stdin);

	move = atoi(move_input);
	return move;
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

int main(int argc, char **argv) {
	int move;
	// X = 1, O = 0
	int symbol = 1;
	initialize_board();

	int board_size = sizeof(board_state) / sizeof(board_state[0]);

	// TODO this is too naive and assumes that the input is always correct
	// make the get move to somehow return if the input is correct or not. e.g -1
	for (int i = 0; i < board_size; i++) {
		print_board();
		move = getmove();
		update_board_state(symbol, move);

		if (symbol == 1) {
			symbol = -1;
		} else {
			symbol = 1;
		}
	}

	return 0;
}