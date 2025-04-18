#include "framework.h"
#include "PlayScene.h"
#include "Player.h"

void PlayScene::Enter()
{
	__super::Enter(); // Scene::Enter(); <- vs에서만 가능. C++표준은아님.
	Player* pPlayer = (Player*)CreateObject<Player>();

}

void PlayScene::Exit()
{
	// 뭔가를 한다.
	__super::Exit();
}

void PlayScene::Update()
{
	Scene::Update();

	// Play하는 Scene은 충돌처리를 더 추가한다.
}
