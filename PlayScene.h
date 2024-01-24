#pragma once
#include "Engine/GameObject.h"

class Text;
class Tank;

class PlayScene :
    public GameObject
{
	Text* pText;
	const int ENEMY_NUM;
	Tank* player;
	int enemyNum;
public:
	PlayScene(GameObject* parent);

	//デストラクタ
	~PlayScene();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
	//インライン定義
	void DescEnemy() { enemyNum--; }
	bool IsEnemyLeft() { return enemyNum > 0; }
	//enemyの合計をとる
	int GetEnemyNum() { return enemyNum; }
};

