#include "framework.h"
#include "PlayScene.h"
#include "Player.h"


void PlayScene::Enter()
{
	__super::Enter(); // __super : Scene::Enter(); < VisualStudio 에서만 가능. C++ 표준아님. 
	// 게임 오브젝트를 상속받은 플레이어나 몬스터 등의 생성 
	Player* player = CreateObject<Player>(); 
	
}

void PlayScene::Exit()
{
	// 뭔가를 한다. 
	__super::Exit(); 
}
