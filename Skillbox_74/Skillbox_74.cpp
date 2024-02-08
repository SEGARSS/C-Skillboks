#include <iostream>
#include <string>

using namespace std;

/*Задание 4. Оценка результатов игры в крестики-нолики
Что нужно сделать
Петя и Вася играли в крестики-нолики и не стёрли результаты своей игры. 
Теперь перед вами табличка 3 × 3, которая осталась после их поединка. 
Вы хотите понять, выиграл ли кто-то из них или они не доиграли.
На вход программе даётся три строки, кодирующие верхнюю, среднюю и нижнюю строчки игрового поля. 
Крестик обозначается символом X (английская заглавная буква X), нолик — символом O (заглавная английская буква O), 
пустая клетка — точкой.
Если ввод некорректен, то есть такая таблица не могла получиться в ходе настоящей игры, то надо написать в ответ слово Incorrect.
Если таблица корректна и выиграли крестики, то нужно вывести в ответ слова Petya won, 
если нолики — Vanya won, иначе (то есть они не доиграли или сыграли вничью) надо написать Nobody.*/

//--------------------------------------------------------------------------------------------------
bool isValidSymbol(char symbol) 
{
	return symbol == 'X' || symbol == 'O' || symbol == '.';
}
//--------------------------------------------------------------------------------------------------
char checkRow(const string& row) 
{
	char winner = row[0];
	for (char symbol : row)
	{
		if (symbol != winner) 
		{
			return '.';
		}
	}
	return winner;
}
//--------------------------------------------------------------------------------------------------
char checkWinner(const string& board) {
	// Check rows
	for (int i = 0; i < 3; ++i) 
	{
		char winner = checkRow(board.substr(i * 3, 3));
		if (winner != '.') 
		{
			return winner;
		}
	}

	// Check columns
	for (int i = 0; i < 3; ++i) 
	{
		char winner = checkRow(board.substr(i, 3));
		if (winner != '.') 
		{
			return winner;
		}
	}

	// Check diagonals
	if (board[0] == board[4] && board[4] == board[8] && board[0] != '.') 
	{
		return board[0];
	}
	if (board[2] == board[4] && board[4] == board[6] && board[2] != '.') 
	{
		return board[2];
	}

	return '.';
}
//--------------------------------------------------------------------------------------------------
bool isValidBoard(const string& board) 
{
	int xCount = 0, oCount = 0;
	for (char symbol : board) 
	{
		if (!isValidSymbol(symbol)) 
		{
			return false;
		}
		if (symbol == 'X') 
		{
			xCount++;
		}
		else if (symbol == 'O') 
		{
			oCount++;
		}
	}
	return abs(xCount - oCount) <= 1;
}
//--------------------------------------------------------------------------------------------------
int main() 
{
	setlocale(LC_ALL,"ru");

	string row1, row2, row3;
	cout << "Введите верхний ряд: ";
	cin >> row1;
	cout << "Введите в средний ряд: ";
	cin >> row2;
	cout << "Введите нижний ряд: ";
	cin >> row3;

	string board = row1 + row2 + row3;

	if (!isValidBoard(board)) 
	{
		cout << "Incorrect" << endl;
		return 0;
	}

	char winner = checkWinner(board);
	if (winner == '.') 
	{
		cout << "Nobody" << endl;
	}
	else if (winner == 'X') 
	{
		cout << "Petya won" << endl;
	}
	else 
	{
		cout << "Vanya won" << endl;
	}

	return 0;
}
//--------------------------------------------------------------------------------------------------
