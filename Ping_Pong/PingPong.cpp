#include "PingPong.h"
extern bool gameover;

int main()
{
	using PP::PingPong;

	PingPong Test;

	Test.Setup();
	Sleep(500);
	while (!gameover)
	{
		Test.Draw();
		Test.input();
		Test.Logic();
	}

	system("pause");
	return 0;
}