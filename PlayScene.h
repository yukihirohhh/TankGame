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

	//�f�X�g���N�^
	~PlayScene();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
	//�C�����C����`
	void DescEnemy() { enemyNum--; }
	bool IsEnemyLeft() { return enemyNum > 0; }
	//enemy�̍��v���Ƃ�
	int GetEnemyNum() { return enemyNum; }
};

