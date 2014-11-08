#include "GameGlobals.h"

CCSize GameGlobals::screen_size_ = CCSizeZero;
int GameGlobals::level_number_ = 0;

void GameGlobals::Init()
{
	screen_size_ = CCDirector::sharedDirector()->getWinSize();
	LoadData();
}

void GameGlobals::LoadData()
{
	// add Resources folder to search path. This is necessary when releasing for win32
	CCFileUtils::sharedFileUtils()->addSearchPath("Resources");

	// load sprite sheet/s

	// load sound effects & background music
}