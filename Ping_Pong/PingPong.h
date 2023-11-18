#pragma once
#ifndef PING_PONG_H_
#define PING_PONG_H_

#include <iostream> 
#include <conio.h>
#include <windows.h>

using std::cout;
using std::endl;

namespace PP
{
	class PingPong
	{
	private:
		float y_racket, y_racket2;
		float x_ball, y_ball;
		int dir_ballX, dir_ballY;
		int score, level;
	public:
		void Setup();
		void Draw();
		void input();
		void Logic();
	};
}

#endif // PING_PONG_H_