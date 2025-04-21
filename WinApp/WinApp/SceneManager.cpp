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

void SceneManager::ShoutDown()
{
}

void SceneManager::ChangeScene() // 현재 씬이 변경 됬을 때 다음 씬으로 변경한다. 
{
	if (next_Scene)
	{
		cur_Scene = next_Scene; 
		next_Scene = nullptr;
	}
}
