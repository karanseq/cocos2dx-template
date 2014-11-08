#ifndef GAME_GLOBALS_H_
#define GAME_GLOBALS_H_

// Global includes go here
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace std;
// Global includes end here

// Helper macros
#define SCREEN_SIZE GameGlobals::screen_size_
#define SOUND_ENGINE CocosDenshion::SimpleAudioEngine::sharedEngine()

// enum used for proper z-ordering
enum EZorder
{
	E_LAYER_BACKGROUND = 0,
	E_LAYER_FOREGROUND = 2,
	E_LAYER_HUD = 6,
	E_LAYER_POPUP = 8,
};

// Helper class containing only static members
class GameGlobals
{
private:
	GameGlobals();
	~GameGlobals();

public:
	// initialise common global data here
	// called when application finishes launching
	static void Init();
	// load initial/all game data here
	static void LoadData();

	static CCSize screen_size_;
	static int level_number_;
};

#endif // GAME_GLOBALS_H_