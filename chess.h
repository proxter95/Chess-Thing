#include <iostream>
#include <string>
#include <array>

using namespace std;
const int MAX_RANK = 56;
const int MIN_RANK = 49;
const int MAX_FILE = 104;
const int MIN_FILE = 97;

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
private:
	position pos;
	string type;
	string color;

public:
	piece();
	piece(position, string, string);

	position getPosition();
	string getType();
	void updatePosition(position);
};

int calc_moves(piece, position);
int knight_moves(position pos, position moves[]);
int bishop_moves(position pos, position moves[]);
int rook_moves(position pos, position moves[]);
int queen_moves(position pos, position moves[]);
int king_moves(position pos, position moves[]);

int main()
{
	position moves[27] = {};
	position pos;
	int num;
	int k = 0;
	char c;

	while (true)
	{
		cout << "Enter the file: ";
		cin >> c;
		pos.setFile(c);
		cout << endl << "Enter the rank: ";
		cin >> c;
		pos.setRank(c);
		cout << endl;

		cout << "Possible Knight moves:" << endl;
		num = knight_moves(pos, moves);

		for (int i = 0; i < num; i = i + 1)
		{
			cout << moves[i].getFile() << moves[i].getRank() << "\t";
			k = k + 1;
			if (k % 10 == 0)
			{
				cout << endl;
			}
		}
		k = 0;
		cout << "\n\n";

		cout << "Possible Bishop moves:" << endl;
		num = bishop_moves(pos, moves);

		for (int i = 0; i < num; i = i + 1)
		{
			cout << moves[i].getFile() << moves[i].getRank() << "\t";
			k = k + 1;
			if (k % 10 == 0)
			{
				cout << endl;
			}
		}
		k = 0;
		cout << "\n\n";

		cout << "Possible Rook moves:" << endl;
		num = rook_moves(pos, moves);

		for (int i = 0; i < num; i = i + 1)
		{
			cout << moves[i].getFile() << moves[i].getRank() << "\t";
			k = k + 1;
			if (k % 10 == 0)
			{
				cout << endl;
			}
		}
		k = 0;
		cout << "\n\n";

		cout << "Possible Queen moves:" << endl;
		num = queen_moves(pos, moves);

		for (int i = 0; i < num; i = i + 1)
		{
			cout << moves[i].getFile() << moves[i].getRank() << "\t";
			k = k + 1;
			if (k % 10 == 0)
			{
				cout << endl;
			}
		}
		k = 0;
		cout << "\n\n";

		cout << "Possible King moves:" << endl;
		num = king_moves(pos, moves);

		for (int i = 0; i < num; i = i + 1)
		{
			cout << moves[i].getFile() << moves[i].getRank() << "\t";
			k = k + 1;
			if (k % 10 == 0)
			{
				cout << endl;
			}
		}
		k = 0;
		cout << "\n\n";
	}
}

//int calc_moves(piece p1, position moves[])
//{
//	int num_moves = 0;
//	if (p1.getType() == "knight")
//	{
//		num_moves = knight_moves(p1.getPosition(), moves);
//	}
//	else if (p1.getType() == "bishop")
//	{
//		num_moves = bishop_moves(p1.getPosition(), moves);
//	}
//	else if (p1.getType() == "rook")
//	{
//		num_moves = bishop_moves(p1.getPosition(), moves);
//	}
//	else if (p1.getType() == "queen")
//	{
//		num_moves = bishop_moves(p1.getPosition(), moves);
//	}
//	else if (p1.getType() == "king")
//	{
//		num_moves = bishop_moves(p1.getPosition(), moves);
//	}
//	else
//	{
//		fill_n(moves, 27, 0);
//	}
//}

int knight_moves(position pos, position moves[])
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

int bishop_moves(position pos, position moves[])
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

int rook_moves(position pos, position moves[])
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

int queen_moves(position pos, position moves[])
{
	position rook[14] = {};
	position bishop[13] = {};
	int rook_positions = rook_moves(pos, rook);
	int bishop_positions = bishop_moves(pos, bishop);
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

int king_moves(position pos, position moves[])
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
}
piece::piece(position init_pos, string type_in, string color_in)
{
	pos = init_pos;
	type = type_in;
	color = color_in;
}
position piece::getPosition()
{
	return pos;
}
string piece::getType()
{
	return type;
}
void piece::updatePosition(position new_pos)
{
	pos = new_pos;
}
