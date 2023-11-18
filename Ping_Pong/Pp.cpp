#include "PingPong.h"
int width = 40; // cordinate x
int height = 25; // cordinate y
bool gameover;

namespace PP
{
	// Start PP;
	void PingPong::Setup()
	{
		gameover = false;
		y_racket = height / 2;
		y_racket2 = height / 2;
		dir_ballX = -1;
		dir_ballY = -1;
		x_ball = width / 2;
		y_ball = height / 2;
		score = level = 0;
	}
	// VOID DRAW MAP
	void PingPong::Draw()
	{
		system("cls");
		for (size_t i = 0; i < width; i++)
			cout << ".";
		cout << endl;
		for (size_t i = 0; i < height; i++)
		{
			for (size_t j = 0; j < width; j++)
			{
				if (j == 0 || j == width - 2)
					cout << ".";
				if (i == y_ball && j == x_ball) // отрисовка шарика
					cout << "O";
				else if (j == 0 && i > y_racket - 3 && i < y_racket + 4) // отрисовка правой ракетки
					cout << "||";
				else if (j == width - 4 && i > y_racket2 - 3 && i < y_racket2 + 4) // отрисовка левой ракетки
					cout << "||";
				else
					cout << " ";
			}
			cout << endl;
		}
		for (size_t i = 0; i < width; i++)
			cout << ".";
		cout << endl;
		cout << "Score = " << score << ", Level = " << level << endl;
	}
	void PingPong::Logic()
	{
		x_ball += dir_ballX;
		y_ball += dir_ballY;
		if (y_ball == 0 || y_ball == height)
			dir_ballY = -dir_ballY;

		if (x_ball == 0 || x_ball == width - 3)
			dir_ballX = -dir_ballX;

		if (x_ball == 0 && (y_ball > y_racket - 3 && y_ball < y_racket + 4))
			score++;
		if (x_ball == width - 3 && (y_ball > y_racket2 - 3 && y_ball < y_racket2 + 4))
			score++;

		if (score == 5)
		{
			score = 0;
			level += 1;
			x_ball = width / 2;
			y_ball = height / 2;
		}
		if (level == 10)
		{
			cout << "##### YOU WIN #####" << endl;
			gameover = true;
		}
	}
	// VOID INPUT
	void PingPong::input()
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w': y_racket -= 1;
				break;
			case 's': y_racket += 1;
				break;
			case 'o': y_racket2 -= 1;
				break;
			case 'l': y_racket2 += 1;
				break;
			case 'q': gameover = true;
				break;
			}
		}
	}
	// End PP;
}