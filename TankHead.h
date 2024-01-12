#pragma once
#include "Engine/GameObject.h"

class TankHead :
    public GameObject
{
private:
	int hModel_; //TankHead�̃��f����ǂޕϐ�
	
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="parent">�e�I�u�W�F�N�g�̃|�C���^</param>
	TankHead(GameObject* parent);

	//�f�X�g���N�^
	~TankHead();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	/// <summary>
	/// ���f���ԍ���Ԃ��֐�
	/// </summary>
	/// <returns>int hModel_ : ���f���ԍ�</returns>
	int GetModelHandle() { return(hModel_); }
};

