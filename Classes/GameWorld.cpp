#include "GameWorld.h"
#include "Popups.h"

GameWorld::GameWorld()
{
	is_popup_active_ = false;
}

GameWorld::~GameWorld()
{}

CCScene* GameWorld::scene()
{
    CCScene *scene = CCScene::create();
    GameWorld *layer = GameWorld::create();
    scene->addChild(layer);
    return scene;
}

bool GameWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }

    // create & add the pause button's menu
	CCMenu* menu = CCMenu::create();
	menu->setAnchorPoint(CCPointZero);
	menu->setPosition(CCPointZero);
	addChild(menu);

	// create & add the pause button
	CCMenuItemSprite* pause_button = CCMenuItemSprite::create(CCSprite::create("pause_button.png"), CCSprite::create("pause_button.png"), this, menu_selector(GameWorld::OnPauseClicked));
	pause_button->setPosition(ccp(SCREEN_SIZE.width * 0.95f, SCREEN_SIZE.height * 0.9f));
	menu->addChild(pause_button);
    return true;
}

void GameWorld::OnPauseClicked(CCObject* sender)
{
	// this prevents multiple pause popups
	if(is_popup_active_)
		return;

	pauseSchedulerAndActions();
	
	// pause game elements here

	// create & add the pause popup
	//PausePopup* pause_popup = PausePopup::create(this);
	//addChild(pause_popup, E_LAYER_POPUP);
	
	Popup* popup = LevelCompletePopup::create(this, 1234);
	addChild(popup, E_LAYER_POPUP);
}

void GameWorld::ResumeGame()
{
	is_popup_active_ = false;

	// resume GameWorld update & Tick functions
	resumeSchedulerAndActions();

	// resume game elements here
}