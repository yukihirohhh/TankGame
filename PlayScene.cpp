#include "PlayScene.h"
#include "Ground.h"
#include "Tank.h"
#include "TankHead.h"
#include "Enemy.h"
#include "Engine/Text.h"
#include "Engine/Camera.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"), pText(nullptr), ENEMY_NUM(5)
{

}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	Instantiate<Tank>(this);
	//Instantiate<TankHead>(this);

	for (int i = 0; i < 30; i++)
	{
		Instantiate<Enemy>(this);
	}
}

void PlayScene::Update()
{
	/*Camera::SetTarget(player->GetPosition());
	XMFLOAT3 camPos = player->GetPosition();
	camPos.y += 8;
	camPos.z -= 15;
	Camera::SetPosition(camPos);*/
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
