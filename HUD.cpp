#include "HUD.h"
#include "Engine/Image.h"
#include "PlayScene.h"
#include <string>


string HUD::EnemyNumString()
{
	//enemy‚ÉPlayScene‚©‚çenemyNum‚ðŽæ‚Á‚Ä‚«‚Ä“ü‚ê‚é
	int enemy = ((PlayScene*)GetParent())->GetEnemyNum();
	//string‚É•ÏŠ·
	string enemyNumString = std::to_string(enemy);
	return enemyNumString;
}

HUD::HUD(GameObject* parent)
	:GameObject(parent, "HUD"), hHUD_(-1), hNumbers_(-1),hKeyHud_(-1)
{
}

HUD::~HUD()
{
}

void HUD::Initialize()
{
	hHUD_ = Image::Load("hud01.png");
	assert(hHUD_ >= 0);
	hNumbers_ = Image::Load("number.png");
	assert(hNumbers_ >= 0);
	hKeyHud_ = Image::Load("KeyTutorial.png");
	assert(hNumbers_ >= 0);

}

void HUD::Update()
{
	tHud_.scale_ = {1.0,1.0,1.0};
	tHud_.position_ = { -0.6,0.85,0 };
	
	tKeyHud_.scale_ = { 0.4,0.4,0.4 };
	tKeyHud_.position_ = {0.68,-0.75,0 };
}

void HUD::Draw()
{
	Image::SetTransform(hHUD_, tHud_);
	Image::Draw(hHUD_);

	Image::SetTransform(hKeyHud_, tKeyHud_);
	Image::Draw(hKeyHud_);

	Transform trans;
	trans.scale_ = { 1.0,1.0,1.0 };
	trans.position_ = { -0.6,0.85,0 };


		string str = EnemyNumString();
		if (str.size() < 2)
				str = std::string(2 - str.size(),'0') + str;
		
		for (int i = 0; i < 2; i++){
			int j = str[i] - '0';

			Image::SetRect(hNumbers_, 51.2 * j, 0, 51.2, 97);
			Image::SetTransform(hNumbers_, trans);
			Image::Draw(hNumbers_);
			trans.position_.x += 0.08;
		}

}

void HUD::Release()
{
}
