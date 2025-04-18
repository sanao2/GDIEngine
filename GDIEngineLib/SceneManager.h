#pragma once

#include "Singleton.h"

class Scene;
class SceneManager : public Singleton<SceneManager>
{
public:
	SceneManager() = default;			// �ٸ� ������ ���� ������ ȣ���� ����
	~SceneManager() = default;

	std::vector<Scene*> m_vScenes; // �� ����Ʈ

	Scene* m_pCurrentScene = nullptr; // ���� ��
	Scene* m_pNextScene = nullptr; // ���� ��
public:
	void Startup();
	void Shutdown();
	void Update();
	void Render();
	void ChangeScene(size_t index);
	Scene* GetCurrentScene() { return m_pCurrentScene; }

	// CreateScene<TestScene>();
	template<typename T>
	void CreateScene()
	{
		Scene* pScene = new T();
		m_vScenes.push_back(pScene);
	}
};