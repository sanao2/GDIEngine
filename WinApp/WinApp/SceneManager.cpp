#include "SceneManager.h"

void SceneManager::Initialize()
{

}

void SceneManager::Update()
{

}

void SceneManager::Render()
{

}

void SceneManager::ChangeScene() // ���� ���� ���� ���� �� ���� ������ �����Ѵ�. 
{
	if (next_Scene)
	{
		cur_Scene = next_Scene; 
	}
}
