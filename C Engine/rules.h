#ifndef RULES_H
#define RULES_H

//     0  1  2  3  4  5  6  7  8  9 10
//  0 [] [] [] [] [] [] [] [] [] [] []
//  1 [] BP BP BD BP wo BP BD BP BP []
//  2 [] BA -- -- BE BK BE -- -- BA []
//  3 [] -- -- -- -- -- -- -- -- -- []
//  4 [] -- -- -- -- bt -- -- -- -- []
//  5 [] -- -- -- -- -- -- -- -- -- []
//  6 [] -- -- -- -- -- -- -- -- -- []
//  7 [] -- -- -- -- -- -- -- -- -- []
//  8 [] -- -- -- -- wt -- -- -- -- []
//  9 [] -- -- -- -- -- -- -- -- -- []
// 10 [] WA -- -- WE WK WE -- -- WA []
// 11 [] WP WP WD WP bo WP WD WP WP []
// 12 [] [] [] [] [] [] [] [] [] [] []

#define ROWS 13
#define COLS 11

// Row Col
#define WHITE_OBJECTIVE_COORD { 1, 5}
#define BLACK_OBJECTIVE_COORD {11, 5}

#define WHITE_TOWER_COORD {8, 5}
#define BLACK_TOWER_COORD {4, 5}

#define TEAM           0b01100000
#define PIECE_TYPE     0b00011111

#define OUT_BOUNDS     0b10000000
#define WHITE          0b01000000
#define BLACK          0b00100000
#define ELEPHANT       0b00010000
#define KNIGHT         0b00001000
#define DRUID          0b00000100
#define ARCHER         0b00000010
#define PAWN           0b00000001
#define EMPTY          0b00000000

#define WHITE_ELEPHANT (WHITE | ELEPHANT)
#define WHITE_KNIGHT   (WHITE | KNIGHT)
#define WHITE_DRUID    (WHITE | DRUID)
#define WHITE_ARCHER   (WHITE | ARCHER)
#define WHITE_PAWN     (WHITE | PAWN)

#define BLACK_ELEPHANT (BLACK | ELEPHANT)
#define BLACK_KNIGHT   (BLACK | KNIGHT)
#define BLACK_DRUID    (BLACK | DRUID)
#define BLACK_ARCHER   (BLACK | ARCHER)
#define BLACK_PAWN     (BLACK | PAWN)

//                          U  UR   R  RD   D  DL   L  LU
#define     PAWN_MOVEMENT { 1,  1,  1,  1,  1,  1,  1,  1}
#define   ARCHER_MOVEMENT { 0,  2,  1,  2,  0,  2,  1,  2}
#define    DRUID_MOVEMENT { 2,  0,  2,  0,  2,  0,  2,  0}
#define   KNIGHT_MOVEMENT {-1,  0, -1,  0, -1,  0, -1,  0}
#define ELEPHANT_MOVEMENT { 1,  1,  0,  0,  0,  0,  0,  1}

#define KNIGHT_MOVEMENT_MINIMUM_FOR_EXTRA 5

#define DEFAULT_BOARD "2pdpnpd2pa2neke2na63nA2nEKE2nA2PDPnPD2P"

char *_REPR = "\
   \0#01\0#02\0#03\0#04\0#05\0#06\0#07\0#08\0#09\0#0a\0#0b\0#0c\0#0d\0#0e\0#0f\0\
#10\0#11\0#12\0#13\0#14\0#15\0#16\0#17\0#18\0#19\0#1a\0#1b\0#1c\0#1d\0#1e\0#1f\0\
#20\0 BP\0 BA\0#23\0 BD\0#25\0#26\0#27\0 BK\0#29\0#2a\0#2b\0#2c\0#2d\0#2e\0#2f\0\
 BE\0#31\0#32\0#33\0#34\0#35\0#36\0#37\0#38\0#39\0#3a\0#3b\0#3c\0#3d\0#3e\0#3f\0\
#40\0 WP\0 WA\0#43\0 WD\0#45\0#46\0#47\0 WK\0#49\0#4a\0#4b\0#4c\0#4d\0#4e\0#4f\0\
 WE\0#51\0#52\0#53\0#54\0#55\0#56\0#57\0#58\0#59\0#5a\0#5b\0#5c\0#5d\0#5e\0#5f\0\
#60\0#61\0#62\0#63\0#64\0#65\0#66\0#67\0#68\0#69\0#6a\0#6b\0#6c\0#6d\0#6e\0#6f\0\
#70\0#71\0#72\0#73\0#74\0#75\0#76\0#77\0#78\0#79\0#7a\0#7b\0#7c\0#7d\0#7e\0#7f\0\
OUT\0#81\0#82\0#83\0#84\0#85\0#86\0#87\0#88\0#89\0#8a\0#8b\0#8c\0#8d\0#8e\0#8f\0\
#90\0#91\0#92\0#93\0#94\0#95\0#96\0#97\0#98\0#99\0#9a\0#9b\0#9c\0#9d\0#9e\0#9f\0\
#a0\0#a1\0#a2\0#a3\0#a4\0#a5\0#a6\0#a7\0#a8\0#a9\0#aa\0#ab\0#ac\0#ad\0#ae\0#af\0\
#b0\0#b1\0#b2\0#b3\0#b4\0#b5\0#b6\0#b7\0#b8\0#b9\0#ba\0#bb\0#bc\0#bd\0#be\0#bf\0\
#c0\0#c1\0#c2\0#c3\0#c4\0#c5\0#c6\0#c7\0#c8\0#c9\0#ca\0#cb\0#cc\0#cd\0#ce\0#cf\0\
#d0\0#d1\0#d2\0#d3\0#d4\0#d5\0#d6\0#d7\0#d8\0#d9\0#da\0#db\0#dc\0#dd\0#de\0#df\0\
#e0\0#e1\0#e2\0#e3\0#e4\0#e5\0#e6\0#e7\0#e8\0#e9\0#ea\0#eb\0#ec\0#ed\0#ee\0#ef\0\
#f0\0#f1\0#f2\0#f3\0#f4\0#f5\0#f6\0#f7\0#f8\0#f9\0#fa\0#fb\0#fc\0#fd\0#fe\0#ff\0";

typedef struct {
	uint row;
	uint col;
} Coord;

typedef unsigned char Turn;

typedef unsigned char Piece;

typedef struct {
	Piece pieces[ROWS][COLS];
} Board;

typedef struct {
	Turn  turn;
	Board board;
} State;

typedef struct {
	Coord from;
	Coord to;
	Piece moving;
	Piece target;
} Move;

typedef struct _MoveNode {
	Move              move;
	struct _MoveNode *parent;
	struct _MoveNode *children;
} MoveNode;

typedef MoveNode *MoveTree;

typedef struct {
	State    state;
	MoveTree moveTree;
} StateTree;

char* repr(Piece p) {
	return &_REPR[4*p]+1;
}

Board* allocBoard() {
	Board* board = malloc(sizeof(Board));
	if (!board) return NULL;
	memset(board->pieces, OUT_BOUNDS, ROWS*COLS);
	return board;
}

void printBoardEx(Board *board) {
	for (uint r = 0; r < ROWS; r++) {
		for (uint c = 0; c < COLS; c++) {
			printf("%s ", repr(board->pieces[r][c]));
		}
		printf("\n");
	}
}

void printBoard(Board *board) {
	for (uint r = 1; r < ROWS-1; r++) {
		for (uint c = 1; c < COLS-1; c++) {
			printf("%s ", repr(board->pieces[r][c]));
		}
		printf("\n");
	}
}

uint initBoard(Board *board, char *boardStr) {
	int index = 12;

	char numbstr[4];
	memset(numbstr, 0, 4);
	uint numbidx = 0;
	uint numb = 1;

	char c;
	Piece p;

	while (1) {
		c = *boardStr++;
		if (!c) break;
		if (isdigit(c)) {
			numbstr[numbidx++] = c;
		} else {
			if (numbidx > 0) numb = atoi(numbstr);
			if (!c) break;
			if      (c == 'n') p = EMPTY;
			else if (c == 'p') p = BLACK | PAWN;
			else if (c == 'a') p = BLACK | ARCHER;
			else if (c == 'd') p = BLACK | DRUID;
			else if (c == 'k') p = BLACK | KNIGHT;
			else if (c == 'e') p = BLACK | ELEPHANT;
			else if (c == 'P') p = WHITE | PAWN;
			else if (c == 'A') p = WHITE | ARCHER;
			else if (c == 'D') p = WHITE | DRUID;
			else if (c == 'K') p = WHITE | KNIGHT;
			else if (c == 'E') p = WHITE | ELEPHANT;
			for (uint i = 0; i < numb; i++) {
				if (index >= (ROWS * COLS)) break;
				uint row = index/COLS;
				uint col = index%COLS;
				board->pieces[row][col] = p;
				index += 2;
				index % COLS == 0 ? index++ : index--;
			}
			// Reset number
			memset(numbstr, 0, 4);
			numbidx = 0;
			numb = 1;
		}
	}

	return !((index/COLS) == (ROWS - 1)) && ((index%COLS) == 1);
}

#endif // RULES_H