#include "framework.h"
#include "PlayScene.h"
#include "Player.h"

void PlayScene::Enter()
{
	__super::Enter(); // Scene::Enter(); <- vs������ ����. C++ǥ�����ƴ�.
	Player* pPlayer = (Player*)CreateObject<Player>();

}

void PlayScene::Exit()
{
	// ������ �Ѵ�.
	__super::Exit();
}

void PlayScene::Update()
{
	Scene::Update();

	// Play�ϴ� Scene�� �浹ó���� �� �߰��Ѵ�.
}
