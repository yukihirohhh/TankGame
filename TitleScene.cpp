#include "TitleScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Image.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent, "ClearScene"), hPict_(-1)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	hPict_ = Image::Load("title.png");
	assert(hPict_ >= 0);
}

void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager
			= (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void TitleScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void TitleScene::Release()
{
}
