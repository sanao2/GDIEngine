#include "framework.h"
#include "PlayScene.h"
#include "Player.h"


void PlayScene::Enter()
{
	__super::Enter(); // __super : Scene::Enter(); < VisualStudio ������ ����. C++ ǥ�ؾƴ�. 
	// ���� ������Ʈ�� ��ӹ��� �÷��̾ ���� ���� ���� 
	Player* player = CreateObject<Player>(); 
	
}

void PlayScene::Exit()
{
	// ������ �Ѵ�. 
	__super::Exit(); 
}
