#pragma once
#include "CGame.h"

#include <windows.h>




short main(short argc, char** argv)
{
	mciSendString("open music.mp3 type mpegvideo alias song1", NULL, 0, 0);
	mciSendString("play song1 repeat", NULL, 0, 0);

	CGame *game = new CGame();
	game->gameProgress(game->getterPlayersArray());
}
