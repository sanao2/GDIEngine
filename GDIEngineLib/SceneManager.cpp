#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"

SceneManager::~SceneManager()
{
	for (auto& scene : m_vScenes)
	{
		delete scene;
	}
	m_vScenes.clear();
}

void SceneManager::Init()
{

}

void SceneManager::Update()
{
	if (m_pNextScene) // �� ��ȯ 
	{
		if (m_pCurrentScene) // ���� ���� EXit ȣ�� 
			m_pCurrentScene->Exit();

		m_pCurrentScene = m_pNextScene;
		m_pNextScene = nullptr;
		
		m_pCurrentScene->Enter(); // ���� �� 
	}

	if (m_pCurrentScene)
		m_pCurrentScene->Update();
}

void SceneManager::Render()
{
	if (m_pCurrentScene)
		m_pCurrentScene->Update();
}

void SceneManager::ChangeScene(size_t index)
{
	if (index >= m_vScenes.size())
		return;

	m_pNextScene = m_vScenes[index];
}
