#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "rules.h"

int main() {
	Board* board = allocBoard();
	int error = initBoard(board, DEFAULT_BOARD);
	if (error) { printf("ERROR\n"); return 1; }

	printBoard(board);

	return 0;
}