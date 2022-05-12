#include <iostream>
#include <string>
#include <array>

using namespace std;
const int MAX_RANK = 56;
const int MIN_RANK = 49;
const int MAX_FILE = 104;
const int MIN_FILE = 97;
const bool WHITE = 1;
const bool BLACK = 0;
const bool YES = 1;
const bool NO = 0;

class position
{
private:
	char file;
	char rank;

public:
	position();
	position(char, char);

	char getRank();
	char getFile();
	void setRank(char new_rank);
	void setFile(char new_file);

};

class piece
{
public:
	position pos;
	bool color;
	string type;

	piece();
	piece(position, bool, string);

	position getPosition();
	bool getColor();
	string getType();

	void setPosition(position);
	void setColor(bool);
	void setType(string);
};

class knight : public piece
{
public:
	knight();
	knight(position, bool);

	int moves(position moves[]);
};

class bishop : public piece
{
public:
	bishop();
	bishop(position, bool);

	int moves(position moves[]);
};

class rook : public piece
{
private:
	bool has_moved;

public:
	rook();
	rook(position, bool);

	int moves(position moves[]);
};

class queen : public piece
{
public:
	queen();
	queen(position, bool);

	int moves(position moves[]);
};

class king : public piece
{
private:
	bool has_moved;

public:
	king();
	king(position, bool);

	int moves(position moves[]);
};

class pawn : public piece
{
public:
	pawn();
	pawn(position, bool);

	int moves(position moves[]);
};

void create_squares(position squares[]) //create an array of positions that contain all 64 possible squares on teh board
{					//length of passed array should be 64 so all squares will fit
	position pos('a','1');
	squares[0] = pos;
	position temp = pos;
	int k = 0;

	for (int i = 1; i <= 8; i = i + 1) //fill squares[] with all 64 possible positions starting at a1 and then moving
	{				   //along the files. Then increment the rank and repeat for all ranks.
		for (int j = 0; j < 8; j = j + 1)
		{
			temp.setFile(static_cast<char>(pos.getFile() + j));
			squares[k] = temp;
			k = k + 1;
		}
		temp.setFile(static_cast<char>(pos.getFile())); //set the file back to 1
		temp.setRank(static_cast<char>(pos.getRank() + i)); //increment the rank 
	}
}

void create_pieces(piece pieces[]) //create an array of all 32 pieces to start the game
{
	position squares[64] = {};
	create_squares(squares);
	
	//create all pawns
	pawn a_pawn_white(squares[8], WHITE);
	pawn a_pawn_black(squares[48], BLACK);
	pawn b_pawn_white(squares[9], WHITE);
	pawn b_pawn_black(squares[49], BLACK);
	pawn c_pawn_white(squares[10], WHITE);
	pawn c_pawn_black(squares[50], BLACK);
	pawn d_pawn_white(squares[11], WHITE);
	pawn d_pawn_black(squares[51], BLACK);
	pawn e_pawn_white(squares[12], WHITE);
	pawn e_pawn_black(squares[52], BLACK);
	pawn f_pawn_white(squares[13], WHITE);
	pawn f_pawn_black(squares[53], BLACK);
	pawn g_pawn_white(squares[14], WHITE);
	pawn g_pawn_black(squares[54], BLACK);
	pawn h_pawn_white(squares[15], WHITE);
	pawn h_pawn_black(squares[55], BLACK);
	//move pawns into pieces[] array
	pieces[0] = a_pawn_white;
	pieces[1] = b_pawn_white;
	pieces[2] = c_pawn_white;
	pieces[3] = d_pawn_white;
	pieces[4] = e_pawn_white;
	pieces[5] = f_pawn_white;
	pieces[6] = g_pawn_white;
	pieces[7] = h_pawn_white;
	pieces[8] = a_pawn_black;
	pieces[9] = b_pawn_black;
	pieces[10] = c_pawn_black;
	pieces[11] = d_pawn_black;
	pieces[12] = e_pawn_black;
	pieces[13] = f_pawn_black;
	pieces[14] = g_pawn_black;
	pieces[15] = h_pawn_black;
	//create knights
	knight knight1_white(squares[1], WHITE);
	knight knight2_white(squares[6], WHITE);
	knight knight1_black(squares[57], BLACK);
	knight knight2_black(squares[62], BLACK);
	//move knights into pieces[] array
	pieces[16] = knight1_white;
	pieces[17] = knight2_white;
	pieces[18] = knight1_black;
	pieces[19] = knight2_black;
	//create bishops
	bishop bishop1_white(squares[2], WHITE);
	bishop bishop2_white(squares[5], WHITE);
	bishop bishop1_black(squares[58], BLACK);
	bishop bishop2_black(squares[61], BLACK);
	//move bishops into pieces[] array
	pieces[20] = bishop1_white;
	pieces[21] = bishop2_white;
	pieces[22] = bishop1_black;
	pieces[23] = bishop2_black;
	//create rooks
	rook rook1_white(squares[0], WHITE);
	rook rook2_white(squares[7], WHITE);
	rook rook1_black(squares[56], BLACK);
	rook rook2_black(squares[63], BLACK);
	//move rooks into pieces[] array
	pieces[24] = rook1_white;
	pieces[25] = rook2_white;
	pieces[26] = rook1_black;
	pieces[27] = rook2_black;
	//create queens
	queen queen_white(squares[3], WHITE);
	queen queen_black(squares[59], BLACK);
	//move queens into pieces[] array
	pieces[28] = queen_white;
	pieces[29] = queen_black;
	//create kings
	king king_white(squares[4], WHITE);
	king king_black(squares[60], BLACK);
	//move kings into pieces[] array
	pieces[30] = king_white;
	pieces[31] = king_black;
}

void printMoves(int num_moves, position moves[])//Print the positions in a given array. num_moves and moves is 
						//calculated using the "moves" method in each piece subclass
{
	int k = 0;
	cout << endl << "The possible moves are:" << endl;
	for (int i = 0; i < num_moves; i = i + 1)
	{
		cout << moves[i].getFile() << moves[i].getRank() << "\t";
		k = k + 1;
		if (k % 10 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}

position::position()
{
	file = 'a';
	rank = '1';
}
position::position(char file_in, char rank_in)
{
	file = file_in;
	rank = rank_in;
}
char position::getRank()
{
	return rank;
}
char position::getFile()
{
	return file;
}
void position::setRank(char new_rank)
{
	rank = new_rank;
}
void position::setFile(char new_file)
{
	file = new_file;
}

piece::piece()
{
	pos.setFile('a');
	pos.setRank('1');
	color = WHITE;
	type = " ";
}
piece::piece(position init_pos, bool color_in, string type_in)
{
	pos = init_pos;
	color = color_in;
	type = type_in;
}
position piece::getPosition()
{
	return pos;
}
bool piece::getColor()
{
	return color;
}
string piece :: getType()
{
	return type;
}
void piece::setPosition(position new_pos)
{
	pos = new_pos;
}
void piece::setColor(bool color_in)
{
	color = color_in;
}
void piece::setType(string type_in)
{
	type = type_in;
}

knight::knight()
{
	pos.setFile('a');
	pos.setRank('1');
	setColor(WHITE);
	setType("knight");
}
knight::knight(position pos, bool color_in)
{
	setPosition(pos);
	setColor(color_in);
	setType("knight");
}
int knight::moves(position moves[])
{
	position temp;
	int i = 0;
	if (int(pos.getFile()) > MAX_FILE or int(pos.getFile()) < MIN_FILE)
	{
		return 0;
	}
	if (int(pos.getRank()) > MAX_RANK or int(pos.getRank()) < MIN_RANK)
	{
		return 0;
	}

	if (pos.getFile() + 2 <= MAX_FILE and pos.getFile() + 2 >= MIN_FILE)
	{
		if (pos.getRank() + 1 >= MIN_RANK and pos.getRank() + 1 <= MAX_RANK)
		{
			temp.setFile(static_cast<char>(pos.getFile() + 2));
			temp.setRank(static_cast<char>(pos.getRank() + 1));
			moves[i] = temp;
			i = i + 1;
		}
		if (pos.getRank() - 1 >= MIN_RANK and pos.getRank() - 1 <= MAX_RANK)
		{
			temp.setFile(static_cast<char>(pos.getFile() + 2));
			temp.setRank(static_cast<char>(pos.getRank() - 1));
			moves[i] = temp;
			i = i + 1;
		}
	}
	if (pos.getFile() - 2 >= MIN_FILE and pos.getFile() - 2 <= MAX_FILE)
	{
		if (pos.getRank() + 1 >= MIN_RANK and pos.getRank() + 1 <= MAX_RANK)
		{
			temp.setFile(static_cast<char>(pos.getFile() - 2));
			temp.setRank(static_cast<char>(pos.getRank() + 1));
			moves[i] = temp;
			i = i + 1;
		}
		if (pos.getRank() - 1 >= MIN_RANK and pos.getRank() - 1 <= MAX_RANK)
		{
			temp.setFile(static_cast<char>(pos.getFile() - 2));
			temp.setRank(static_cast<char>(pos.getRank() - 1));
			moves[i] = temp;
			i = i + 1;
		}
	}
	if (pos.getRank() + 2 <= MAX_RANK and pos.getRank() + 2 >= MIN_RANK)
	{
		if (pos.getFile() + 1 <= MAX_FILE and pos.getFile() + 1 >= MIN_FILE)
		{
			temp.setFile(static_cast<char>(pos.getFile() + 1));
			temp.setRank(static_cast<char>(pos.getRank() + 2));
			moves[i] = temp;
			i = i + 1;
		}
		if (pos.getFile() - 1 <= MAX_FILE and pos.getFile() - 1 >= MIN_FILE)
		{
			temp.setFile(static_cast<char>(pos.getFile() - 1));
			temp.setRank(static_cast<char>(pos.getRank() + 2));
			moves[i] = temp;
			i = i + 1;
		}
	}
	if (pos.getRank() - 2 >= MIN_RANK and pos.getRank() - 2 <= MAX_RANK)
	{
		if (pos.getFile() + 1 <= MAX_FILE and pos.getFile() + 1 >= MIN_FILE)
		{
			temp.setFile(static_cast<char>(pos.getFile() + 1));
			temp.setRank(static_cast<char>(pos.getRank() - 2));
			moves[i] = temp;
			i = i + 1;
		}
		if (pos.getFile() - 1 <= MAX_FILE and pos.getFile() - 1 >= MIN_FILE)
		{
			temp.setFile(static_cast<char>(pos.getFile() - 1));
			temp.setRank(static_cast<char>(pos.getRank() - 2));
			moves[i] = temp;
			i = i + 1;
		}
	}
	return i;
}

bishop::bishop()
{
	pos.setFile('a');
	pos.setRank('1');
	setColor(WHITE);
	setType("bishop");
}
bishop::bishop(position pos, bool color_in)
{
	setPosition(pos);
	setColor(color_in);
	setType("bishop");
}
int bishop::moves(position moves[])
{
	position temp;
	int i = 1;
	int j = 0;
	if (int(pos.getFile()) > MAX_FILE or int(pos.getFile()) < MIN_FILE)
	{
		return 0;
	}
	if (int(pos.getRank()) > MAX_RANK or int(pos.getRank()) < MIN_RANK)
	{
		return 0;
	}
	while (pos.getFile() + i <= MAX_FILE and pos.getFile() + i >= MIN_FILE)
	{
		temp.setFile((static_cast<char>(pos.getFile() + i)));
		if (pos.getRank() + i <= MAX_RANK and pos.getRank() + i >= MIN_RANK)
		{
			temp.setRank((static_cast<char>(pos.getRank() + i)));
			moves[j] = temp;
			j = j + 1;
		}
		if (pos.getRank() - i <= MAX_RANK and pos.getRank() - i >= MIN_RANK)
		{
			temp.setRank((static_cast<char>(pos.getRank() - i)));
			moves[j] = temp;
			j = j + 1;
		}
		i = i + 1;
	}

	i = 1;

	while (pos.getFile() - i <= MAX_FILE and pos.getFile() - i >= MIN_FILE)
	{
		temp.setFile((static_cast<char>(pos.getFile() - i)));
		if (pos.getRank() - i <= MAX_RANK and pos.getRank() - i >= MIN_RANK)
		{
			temp.setRank((static_cast<char>(pos.getRank() - i)));
			moves[j] = temp;
			j = j + 1;
		}
		if (pos.getRank() + i <= MAX_RANK and pos.getRank() + i >= MIN_RANK)
		{
			temp.setRank((static_cast<char>(pos.getRank() + i)));
			moves[j] = temp;
			j = j + 1;
		}
		i = i + 1;
	}

	return j;
}

rook::rook()
{
	pos.setFile('a');
	pos.setRank('1');
	setColor(WHITE);
	has_moved = NO;
	setType("rook");
}
rook::rook(position pos, bool color_in)
{
	setPosition(pos);
	setColor(color_in);
	has_moved = NO;
	setType("rook");
}

int rook::moves(position moves[])
{
	position temp = pos;
	int i = 1;
	int j = 0;
	if (int(pos.getFile()) > MAX_FILE or int(pos.getFile()) < MIN_FILE)
	{
		return 0;
	}
	if (int(pos.getRank()) > MAX_RANK or int(pos.getRank()) < MIN_RANK)
	{
		return 0;
	}
	while (pos.getFile() + i <= MAX_FILE and pos.getFile() + i >= MIN_FILE)
	{
		temp.setFile((static_cast<char>(pos.getFile() + i)));
		moves[j] = temp;
		j = j + 1;
		i = i + 1;
	}
	i = 1;
	while (pos.getFile() - i <= MAX_FILE and pos.getFile() - i >= MIN_FILE)
	{
		temp.setFile((static_cast<char>(pos.getFile() - i)));
		moves[j] = temp;
		j = j + 1;
		i = i + 1;
	}
	i = 1;
	temp.setFile(pos.getFile());
	while (pos.getRank() + i <= MAX_RANK and pos.getRank() + i >= MIN_RANK)
	{
		temp.setRank((static_cast<char>(pos.getRank() + i)));
		moves[j] = temp;
		j = j + 1;
		i = i + 1;
	}
	i = 1;
	while (pos.getRank() - i <= MAX_RANK and pos.getRank() - i >= MIN_RANK)
	{
		temp.setRank((static_cast<char>(pos.getRank() - i)));
		moves[j] = temp;
		j = j + 1;
		i = i + 1;
	}
	return j;

}

queen::queen()
{
	pos.setFile('a');
	pos.setRank('1');
	setColor(WHITE);
	setType("queen");
}
queen::queen(position pos, bool color_in)
{
	setPosition(pos);
	setColor(color_in);
	setType("queen");
}

int queen::moves(position moves[])
{
	rook temp_rook(pos, WHITE);
	bishop temp_bishop(pos, WHITE);
	position rook[14] = {};
	position bishop[13] = {};
	int rook_positions = temp_rook.moves(rook);
	int bishop_positions = temp_bishop.moves(bishop);
	int i = 0;
	int j = 0;

	for (i = 0; i < rook_positions; i = i + 1)
	{
		moves[i] = rook[i];
		j = j + 1;
	}
	for (i = 0; i < bishop_positions; i = i + 1)
	{
		moves[i + rook_positions] = bishop[i];
		j = j + 1;
	}
	return j;
}

king::king()
{
	pos.setFile('a');
	pos.setRank('1');
	setColor(WHITE);
	has_moved = NO;
	setType("king");
}
king::king(position pos, bool color_in)
{
	setPosition(pos);
	setColor(color_in);
	has_moved = NO;
	setType("king");
}

int king::moves(position moves[])
{
	position temp = pos;
	int i = 0;
	if (int(pos.getFile()) > MAX_FILE or int(pos.getFile()) < MIN_FILE)
	{
		return 0;
	}
	if (int(pos.getRank()) > MAX_RANK or int(pos.getRank()) < MIN_RANK)
	{
		return 0;
	}
	if (pos.getRank() + 1 <= MAX_RANK and pos.getRank() + 1 >= MIN_RANK)
	{
		temp.setRank(static_cast<char>(pos.getRank() + 1));
		moves[i] = temp;
		i = i + 1;
	}
	if (pos.getRank() - 1 <= MAX_RANK and pos.getRank() - 1 >= MIN_RANK)
	{
		temp.setRank(static_cast<char>(pos.getRank() - 1));
		moves[i] = temp;
		i = i + 1;
	}
	temp = pos;

	if (pos.getFile() + 1 <= MAX_FILE and pos.getFile() + 1 >= MIN_FILE)
	{
		temp.setFile(static_cast<char>(pos.getFile() + 1));
		moves[i] = temp;
		i = i + 1;
		if (pos.getRank() + 1 <= MAX_RANK and pos.getRank() + 1 >= MIN_RANK)
		{
			temp.setRank(static_cast<char>(pos.getRank() + 1));
			moves[i] = temp;
			i = i + 1;
		}
		if (pos.getRank() - 1 <= MAX_RANK and pos.getRank() - 1 >= MIN_RANK)
		{
			temp.setRank(static_cast<char>(pos.getRank() - 1));
			moves[i] = temp;
			i = i + 1;
		}
	}
	temp = pos;
	if (pos.getFile() - 1 <= MAX_FILE and pos.getFile() - 1 >= MIN_FILE)
	{
		temp.setFile(static_cast<char>(pos.getFile() - 1));
		moves[i] = temp;
		i = i + 1;
		if (pos.getRank() + 1 <= MAX_RANK and pos.getRank() + 1 >= MIN_RANK)
		{
			temp.setRank(static_cast<char>(pos.getRank() + 1));
			moves[i] = temp;
			i = i + 1;
		}
		if (pos.getRank() - 1 <= MAX_RANK and pos.getRank() - 1 >= MIN_RANK)
		{
			temp.setRank(static_cast<char>(pos.getRank() - 1));
			moves[i] = temp;
			i = i + 1;
		}
	}

	return i;
}

pawn::pawn()
{
	pos.setFile('a');
	pos.setRank('1');
	setColor(WHITE);
	setType("pawn");
}
pawn::pawn(position pos, bool color_in)
{
	setPosition(pos);
	setColor(color_in);
	setType("pawn");
}

int pawn::moves(position moves[])
{
	position temp = pos;
	int i = 0;
	temp.setRank(static_cast<char>(pos.getRank() + 1));
	moves[i] = temp;
	i = i + 1;
	if (pos.getRank() == '2')
	{
		temp.setRank(static_cast<char>(pos.getRank() + 2));
		moves[i] = temp;
		i = i + 1;
	}
	return i;
}
