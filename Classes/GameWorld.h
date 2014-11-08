#ifndef GAME_WORLD_H_
#define GAME_WORLD_H_

#include "GameGlobals.h"

class GameWorld : public CCLayer
{
public:
	GameWorld();
	virtual ~GameWorld();

    virtual bool init();

    static CCScene* scene();    
    CREATE_FUNC(GameWorld);

	void OnPauseClicked(CCObject* sender);
	void ResumeGame();
public:
	bool is_popup_active_;
};

#endif // GAME_WORLD_H_